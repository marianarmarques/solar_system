#include <GL/glut.h>
#include "headers/point.hpp"
#include "headers/tags.hpp"
#include <math.h>

static int drawMode = 0, eixos = 0;
static float alpha, betha, radius;
Point position, lookAt, up, projection;

Tags tagsXML = Tags();

void drawTriangle(Point p1, Point p2, Point p3)
{
    glBegin(GL_TRIANGLES);
    glVertex3f(p1.getX(), p1.getY(), p1.getZ());
    glVertex3f(p2.getX(), p2.getY(), p2.getZ());
    glVertex3f(p3.getX(), p3.getY(), p3.getZ());
    glEnd();
}

void drawModel(Model model)
{
    for (int i = 0; i < model.getPoints()->size(); i += 3) {
        drawTriangle(model.getPoints()->at(i), model.getPoints()->at(i + 1), model.getPoints()->at(i + 2));
    }
}


void drawGroup(Group group){
    glPushMatrix();
    glColor3f(group.getColor().getR(), group.getColor().getG(), group.getColor().getB());

    // Transformations
    for(int i = 0; i < group.getTransforms().getTransforms().size(); i++) {
        group.getTransforms().getTransforms().at(i)->doAction();
    }

    //Models
    for (Model model : group.getModels().getModels()) {
        drawModel(model);
    }

    for(Group g: group.getGroups()){
        drawGroup(g);  
    }

    glPopMatrix();
}

void moveCamera(){
    position.setX(radius * cos(betha) * sin(alpha));
    position.setY(radius * sin(betha));
    position.setZ(radius * cos(betha) * cos(alpha));   
}

void convertToSpherical() {

    if (position.getX() == 0) position.setX(0.0000001);
    if (position.getY() == 0) position.setY(0.0000001);
    if (position.getZ() == 0) position.setZ(0.0000001);

    alpha = atan(position.getX() / position.getZ());
    betha = tan((position.getY() * sin(alpha)) / position.getX());

    if (betha >= M_PI / 2) betha -= M_PI;
    if (betha <= -M_PI / 2) betha += M_PI;

    radius = position.getY() / sin(betha);
}

void draw_axis(void)
{
    glBegin(GL_LINES);

    // X axis in red
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(100.0f, 0.0f, 0.0f);

    // Y Axis in Green
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 100.0f, 0.0f);

    // Z Axis in Blue
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 100.0f);
    glEnd();
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
    gluPerspective(projection.getX(), 
                   ratio, 
                   projection.getY(), 
                   projection.getZ());

    // return to the model view matrix mode
    glMatrixMode(GL_MODELVIEW);
}

void renderScene()
{
    // clear buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // set the camera
    glLoadIdentity();

    moveCamera();
    gluLookAt(position.getX(), position.getY(), position.getZ(), 
              lookAt.getX(), lookAt.getY(), lookAt.getZ(),
              up.getX(), up.getY(), up.getZ());

    // draw 
    if (eixos)
        draw_axis();
    
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

    drawGroup(tagsXML.getGroup());

    // end of frame
    glutSwapBuffers();
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
        radius += 2;
        break;
    
    case '-':
        radius -= 2;
        break;
    
    case '.':
        eixos = 1 - eixos;

    default:
        break;
    }
    
    if (radius <= 0) radius = 1;

    glutPostRedisplay();
}


void processSpecialKeys(int key, int xx, int yy) {

    switch (key)
    {
        case GLUT_KEY_UP:
            betha += 0.1;
            break;
        
        case GLUT_KEY_DOWN:
            betha -= 0.1;
            break;
        
        case GLUT_KEY_LEFT:
            alpha -= 0.1;
            break;
        
        case GLUT_KEY_RIGHT:
            alpha += 0.1;
            break;
        
        default:
            break;
    }

    if (betha >= 1.5) betha = 1.5;
    if (betha <= -1.5) betha = -1.5;

    glutPostRedisplay();
}

int main(int argc, char **argv) {

    if (argc != 2) {
        return 0;
    }

    std::string filename = std::string("../xmlFiles/") + argv[1];
    tagsXML = readXML(filename.c_str());
    //tagsXML.printTags();

    position = tagsXML.getCamera().getPosition();
    lookAt = tagsXML.getCamera().getLookAt();
    up = tagsXML.getCamera().getUp();
    projection = tagsXML.getCamera().getProjection();
    
    convertToSpherical();

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

    //  OpenGL settings
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    // enter GLUT's main cycle
    glutMainLoop();

    return 1;
}