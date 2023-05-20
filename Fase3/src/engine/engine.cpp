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
    glPushMatrix();
    glColor3f(group.getColor().getR(), group.getColor().getG(), group.getColor().getB());

    // Transformations
    for(int i = 0; i < group.getTransforms().getTransforms().size(); i++) {        
        group.getTransforms().getTransforms().at(i)->doAction(elapsed);
    }

    //Models
    for (Model model : group.getModels().getModels()) {
        __glewBindBuffer(GL_ARRAY_BUFFER, model.getPair().first);
        glVertexPointer(3, GL_FLOAT, 0, 0);
        glDrawArrays(GL_TRIANGLES, 0, model.getPair().second);
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

    // set the camera
    glLoadIdentity();

    cam.moveCamera();

    gluLookAt(cam.getPosition().getX(), cam.getPosition().getY(), cam.getPosition().getZ(), 
              cam.getLookAt().getX(), cam.getLookAt().getY(), cam.getLookAt().getZ(),
              cam.getUp().getX(), cam.getUp().getY(), cam.getUp().getZ());

    // draw 
    if (eixos)
        draw_axis();
    
    updateDrawMode();

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
            cam.setRadius(2, '-');
            break;
        
        case '-':
            cam.setRadius(2, '+');
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
    glewInit();
    glEnableClientState(GL_VERTEX_ARRAY);
    
    //  OpenGL settings
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    std::string filename = std::string("../xmlFiles/") + argv[1];
    tagsXML = readXML(filename.c_str());

    cam = tagsXML.getCamera();
    
    cam.convertToSpherical();

    timebase = glutGet(GLUT_ELAPSED_TIME);

    // enter GLUT's main cycle
    glutMainLoop();

    return 1;
}