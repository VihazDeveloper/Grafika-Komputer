#include <GL/glew.h>
#include <GL/freeglut.h>

static float X = 0.0;
static float Y = 0.0;
static float Z = -15.0;

static GLUquadric *qobj;

// Drawing routine.
void drawScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glLoadIdentity();

    // Modeling transformations.

    // shape 1
    glPushMatrix();
    gluPartialDisk(qobj, 0.0, 10.0, 1000.0, 1.0, 0.0, 60.0);
    glPopMatrix();


    /*
    // shape 1
    glPushMatrix();
    glTranslatef(X, Y, Z);
    glRotatef(60.0, 0.0, 1.0, 0.0);
    glRotatef(60.0, 1.0, 0.0, 1.0);
    glutSolidCone(3.0, 5.5, 20.0, 5.0);
    glPopMatrix();
    // shape 2
    glPushMatrix();
    glTranslatef(2.0, 4.0, Z);
    glRotatef(60.0, 0.0, 1.0, 0.0);
    glRotatef(-90.0, 1.0, 0.0, 1.0);
    glutSolidCone(3.0, 5.5, 20.0, 5.0);
    glPopMatrix();
    */

    glFlush();
}

// Initialization routine.
void setup(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
        break;
    case 'a':
        X += 0.5;
        glutPostRedisplay();
        break;
    case 'd':
        X -= 0.5;
        glutPostRedisplay();
        break;
    case 's':
        Y -= 0.5;
        glutPostRedisplay();
        break;
    case 'w':
        Y += 0.5;
        glutPostRedisplay();
        break;
    case 'q':
        Z -= 0.5;
        glutPostRedisplay();
        break;
    case 'e':
        Z += 0.5;
        glutPostRedisplay();
        break;
    default:
        break;
    }
}

// Main routine.
int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    glutInitContextVersion(4, 3);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("circle-cone.cpp");
    glutDisplayFunc(drawScene);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyInput);

    glewExperimental = GL_TRUE;
    glewInit();

    setup();

    glutMainLoop();
}