#include "headers/group.hpp"

static int drawMode = 0, eixos = 0;
double timebase, elapsed = 0;
Camera cam;

Tree tagsXML = Tree();

double chekkFPS(){
    double time = glutGet(GLUT_ELAPSED_TIME);
    double elapsed = (time - timebase)/1000;
    return  elapsed;
}

void drawGroup(Group group){
    float white[4] = {1.0, 1.0, 1.0, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, white);
    glPushMatrix();

    // Transformations
    for(int i = 0; i < group.getTransforms().getTransforms().size(); i++) {        
        group.getTransforms().getTransforms().at(i)->doAction(elapsed);
    }

    //Models
    for (Model model : group.getModels().getModels()) {
        // Color
        model.getColor().doColor();

        // VBOs
        glBindBuffer(GL_ARRAY_BUFFER, model.getBuffers()[0]);
        glVertexPointer(3, GL_FLOAT, 0, 0);

        if(!model.getNormals().empty()) 
        {
            glBindBuffer(GL_ARRAY_BUFFER, model.getBuffers()[1]);
            glNormalPointer(GL_FLOAT, 0, 0);
        }

        if(!model.getTextureModel().second.empty()) 
        {
            glBindBuffer(GL_ARRAY_BUFFER, model.getBuffers()[2]);
            glTexCoordPointer(2, GL_FLOAT, 0, 0);

            glBindTexture(GL_TEXTURE_2D, tagsXML.getMapTextures().at(model.getTextureModel().first));
        }

        glEnable(GL_LIGHTING);
        glDrawArrays(GL_TRIANGLES, 0, model.getPoints().size());

        glBindTexture(GL_TEXTURE_2D, 0);
        glDisable(GL_LIGHTING);
    }    

    for(Group g: group.getGroups()){
        drawGroup(g);  
    }

    glPopMatrix();
    
}

void draw_axis(void)
{
    glBegin(GL_LINES);

    // X axis in red
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(500.0f, 0.0f, 0.0f);

    // Y Axis in Green
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 500.0f, 0.0f);

    // Z Axis in Blue
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 500.0f);

    glEnd();
}

void updateDrawMode() {
    switch (drawMode)
    {
        case 0:
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            break;
        case 1:
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            break;
        case 2:
            glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
            break;
        default:
            break;
    }
}

void changeSize(int w, int h) {

    // Prevent a divide by zero, when window is too short
    // (you cant make a window with zero width).
    if (h == 0)
        h = 1;

    // compute window's aspect ratio
    float ratio = w * 1.0 / h;

    // Set the projection matrix as current
    glMatrixMode(GL_PROJECTION);

    // Load Identity Matrix
    glLoadIdentity();

    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);

    // Set perspective
    gluPerspective(cam.getProjection().getX(), 
                   ratio, 
                   cam.getProjection().getY(), 
                   cam.getProjection().getZ());

    // return to the model view matrix mode
    glMatrixMode(GL_MODELVIEW);
}

void renderScene()
{
    // clear buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (eixos)
        draw_axis();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    updateDrawMode();

    cam.moveCamera();

    gluLookAt(cam.getPosition().getX(), cam.getPosition().getY(), cam.getPosition().getZ(), 
              cam.getLookAt().getX(), cam.getLookAt().getY(), cam.getLookAt().getZ(),
              cam.getUp().getX(), cam.getUp().getY(), cam.getUp().getZ());

    for(auto light : tagsXML.getLights().getLights()) {
        light->doAction();
    }

    drawGroup(tagsXML.getGroup());

    elapsed = chekkFPS();

    // end of frame
    glutSwapBuffers();

    // always update the time
    glutPostRedisplay();
}


void processKeys(unsigned char c, int xx, int yy) {
    switch (c)
    {
        case '0':
            drawMode = 0;
            break;

        case '1':
            drawMode = 1;
            break;
        
        case '2':
            drawMode = 2;
            break;
        
        case '+':
            cam.setRadius(1, '-');
            break;
        
        case '-':
            cam.setRadius(1, '+');
            break;
        
        case '.':
            eixos = 1 - eixos;

        default:
            break;
    }
    
    if (cam.getRadius() <= 0) cam.setRadius(1, '=');
    if (cam.getRadius() >= 500) cam.setRadius(500, '=');
}


void processSpecialKeys(int key, int xx, int yy) {
    switch (key)
    {
        case GLUT_KEY_UP:
            cam.setBetha(0.1, '+');
            break;
        
        case GLUT_KEY_DOWN:
            cam.setBetha(0.1, '-');
            break;
        
        case GLUT_KEY_LEFT:
            cam.setAlpha(0.1, '-');
            break;
        
        case GLUT_KEY_RIGHT:
            cam.setAlpha(0.1, '+');
            break;
        
        default:
            break;
    }
    
    if (cam.getBetha() >= 1.5) cam.setBetha(1.5, '=');
    if (cam.getBetha() <= -1.5) cam.setBetha(1.5, '=');
}

int main(int argc, char **argv) {

    if (argc != 2) {
        printf("Not enough arguments\n");
        return 0;
    }
    
    // init GLUT and the window 
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 800);
    glutCreateWindow("CG@DI-UM");

    // Required callback registry
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);

    // Callback registration for keyboard processing
    glutKeyboardFunc(processKeys);
    glutSpecialFunc(processSpecialKeys);
    
    // Init glew
    glewInit();
    ilInit();

    //  OpenGL settings
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_NORMALIZE);
    glEnable(GL_RESCALE_NORMAL);
    glEnable(GL_TEXTURE_2D);
    ilEnable(IL_ORIGIN_SET);
    ilOriginFunc(IL_ORIGIN_LOWER_LEFT);

    std::string filename = std::string("../xmlFiles/") + argv[1];
    tagsXML = readXML(filename.c_str());

    for(auto texture : tagsXML.getMapTextures()) {
        printf("%s %d\n", texture.first.c_str(), texture.second);
    }

    cam = tagsXML.getCamera();
    cam.convertToSpherical();
    

    int lightSize = (int) tagsXML.getLights().getLights().size();

    float dark[4] = {0.2, 0.2, 0.2, 1.0};
    float white[4] = {1.0, 1.0, 1.0, 1.0};

    for(int i=0; i<lightSize; i++) {
        glEnable(GL_LIGHT0 + i);
        glLightfv(GL_LIGHT0 + i, GL_AMBIENT, dark);
        glLightfv(GL_LIGHT0 + i, GL_DIFFUSE, white);
        glLightfv(GL_LIGHT0 + i, GL_SPECULAR, white);
    }
    
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, white);

    timebase = glutGet(GLUT_ELAPSED_TIME);

    // enter GLUT's main cycle
    glutMainLoop();

    return 1;
}