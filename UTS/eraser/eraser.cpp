// ANGGOTA KELOMPOK :
// 5221600017  David Dinhaz
// 5221600025  Raila Ardha F A


#define _USE_MATH_DEFINES 
#include <windows.h>
#include <cstdlib>
#include <cmath>
#include <GL/glew.h>
#include <GL/freeglut.h>

/* Global variables */
char title[] = "PROJECT 1 - ERASER";
GLfloat anglePyramid = 0.0f;
GLfloat angleCube = 0.0f;
int refreshMills = 15;

void initGL()
{
    glClearColor(0.0f, 0.5f, 1.0f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    glTranslatef(1.5f, 0.0f, -7.0f);
    glRotatef(angleCube, 1.0f, 1.0f, 1.0f);

    glBegin(GL_QUADS);

    //KAIN
    glColor3f(0.0f, 0.0f, 0.1f);     // Green
    glVertex3f( 1.5f, 0.5f, -0.1f);
    glVertex3f(-1.5f, 0.5f, -0.1f);
    glVertex3f(-1.5f, 0.5f,  0.1f);
    glVertex3f( 1.5f, 0.5f,  0.1f);

    // Bottom face (y = -1.0f)
    glColor3f(0.0f, 0.0f, 0.1f);     // Orange
    glVertex3f( 1.5f, -0.5f,  0.1f);
    glVertex3f(-1.5f, -0.5f,  0.1f);
    glVertex3f(-1.5f, -0.5f, -0.1f);
    glVertex3f( 1.5f, -0.5f, -0.1f);

    // Front face  (z = 1.0f)
    glColor3f(0.0f, 0.0f, 0.1f);     // Red
    glVertex3f( 1.5f,  0.5f, 0.1f);
    glVertex3f(-1.5f,  0.5f, 0.1f);
    glVertex3f(-1.5f, -0.5f, 0.1f);
    glVertex3f( 1.5f, -0.5f, 0.1f);

    // Back face (z = -1.0f)
    glColor3f(0.0f, 0.0f, 0.1f);     // Yellow
    glVertex3f( 1.5f, -0.5f, -0.1f);
    glVertex3f(-1.5f, -0.5f, -0.1f);
    glVertex3f(-1.5f,  0.5f, -0.1f);
    glVertex3f( 1.5f,  0.5f, -0.1f);

    // Left face (x = -1.0f)
    glColor3f(0.0f, 0.0f, 0.1f);     // Blue
    glVertex3f(-1.5f,  0.5f,  0.1f);
    glVertex3f(-1.5f,  0.5f, -0.1f);
    glVertex3f(-1.5f, -0.5f, -0.1f);
    glVertex3f(-1.5f, -0.5f,  0.1f);

    // Right face (x = 1.0f)
    glColor3f(0.0f, 0.0f, 0.1f);     // Magenta
    glVertex3f(1.5f,  0.5f, -0.1f);
    glVertex3f(1.5f,  0.5f,  0.1f);
    glVertex3f(1.5f, -0.5f,  0.1f);
    glVertex3f(1.5f, -0.5f, -0.1f);

    // BADAN
    //Top face
    glColor3f(0.91f, 0.76f, 0.65f);     // Yellow
    glVertex3f( 1.45f, 0.45f, 0.11f);
    glVertex3f(-1.45f, 0.45f, 0.11f);
    glVertex3f(-1.45f, 0.45f, 0.55f);
    glVertex3f( 1.45f, 0.45f, 0.55f);

    // Bottom face (y = -1.0f)
    glColor3f(0.91f, 0.76f, 0.65f);     // Orange
    glVertex3f( 1.45f, -0.45f, 0.55f);
    glVertex3f(-1.45f, -0.45f, 0.55f);
    glVertex3f(-1.45f, -0.45f, 0.11f);
    glVertex3f( 1.45f, -0.45f, 0.11f);

    // Front face  (z = 1.0f)
    glColor3f(0.91f, 0.76f, 0.65f);     // Red
    glVertex3f( 1.45f,  0.45f, 0.55f);
    glVertex3f(-1.45f,  0.45f, 0.55f);
    glVertex3f(-1.45f, -0.45f, 0.55f);
    glVertex3f( 1.45f, -0.45f, 0.55f);

    // Left face (x = -1.0f)
    glColor3f(0.91f, 0.76f, 0.65f);     // Blue
    glVertex3f(-1.45f,  0.45f, -0.0f);
    glVertex3f(-1.45f,  0.45f, 0.55f);
    glVertex3f(-1.45f, -0.45f, 0.55f);
    glVertex3f(-1.45f, -0.45f, -0.0f);

    // right face
    glColor3f(0.91f, 0.76f, 0.65f);     // Magenta
    glVertex3f(1.45f,  0.45f, 0.55f);
    glVertex3f(1.45f,  0.45f, -0.0f);
    glVertex3f(1.45f, -0.45f, -0.0f);
    glVertex3f(1.45f, -0.45f, 0.55f);
    
    
    // PEGANGAN
    glColor3f(1.0f, 1.0f, 1.0f);     // Green
    glVertex3f( 1.45f, 0.45f, 0.55f);
    glVertex3f(-1.45f, 0.45f, 0.55f);
    glVertex3f(-1.55f, 0.5f, 0.65f);
    glVertex3f( 1.55f, 0.5f, 0.65f);
    
    // Bottom face (y = -1.0f)
    glColor3f(1.0f, 1.0f, 1.0f);     // Orange
    glVertex3f( 1.55f, -0.5f, 0.65f);
    glVertex3f(-1.55f, -0.5f, 0.65f);
    glVertex3f(-1.45f, -0.45f, 0.55f);
    glVertex3f( 1.45f, -0.45f, 0.55f);

    // Front face  (z = 1.0f)
    glColor3f(1.0f, 1.0f, 1.0f);     // Red
    glVertex3f( 1.55f,  0.5f, 0.65f);
    glVertex3f(-1.55f,  0.5f, 0.65f);
    glVertex3f(-1.55f, -0.5f, 0.65f);
    glVertex3f( 1.55f, -0.5f, 0.65f);

    // Left face (x = -1.0f)
    glColor3f(1.0f, 1.0f, 1.0f);     // Blue
    glVertex3f(-1.55f, 0.5f, 0.65f);
    glVertex3f(-1.45f, 0.45f, 0.55f);
    glVertex3f(-1.45f, -0.45f, 0.55f);
    glVertex3f(-1.55f, -0.5f, 0.65f);

    // right face
    glColor3f(1.0f, 1.0f, 1.0f);     // Magenta
    glVertex3f(1.55f,  0.5f, 0.65f);
    glVertex3f(1.45f,  0.45f, 0.55f);
    glVertex3f(1.45f, -0.45f, 0.55f);
    glVertex3f(1.55f, -0.5f, 0.65f);

    glEnd(); 

    glutSwapBuffers();

    angleCube -= 0.15f;
}

void timer(int value)
{
    glutPostRedisplay();
    glutTimerFunc(refreshMills, timer, 0);
}

void reshape(GLsizei width, GLsizei height)
{
    if (height == 0) height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(25, 50);
    glutCreateWindow(title);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    initGL();
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}