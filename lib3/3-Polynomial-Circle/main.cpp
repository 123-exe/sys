#include<windows.h>
#include<stdio.h>
#include<math.h>
#include<GL/gl.h>
#include<GL/glut.h>

const int screenWidth = 640 * 2;
const int screenHeight = 480 * 2;
GLdouble A, B, C, D;    // Values for scaling and shifting

void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);   // Background color is white
    glColor3f(0.0f, 0.0f, 0.0f);    // Drawing color is black
    glLineWidth(4.0);   // A line is 4 times thicker

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    A = screenWidth / 4.0;  // Set values for scaling and shifting
    B = 0.0;
    C = D = screenHeight / 2.0;

    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the screen

    glPointSize(4.0);

    GLint r = 100, i = 1;
    GLint h = 300, k = 300, x, x2, y;

    x2 = r / sqrt(2);

    for(x = 0; x <= x2; x++)
    {
        y = sqrt(pow(r, 2) - pow(x, 2));

         glBegin(GL_POINTS);
        {
            glVertex2i(x+h, k+y);
            glVertex2i(x+h, k-y);

            glVertex2i(y+h, k+x);
            glVertex2i(y+h, k-x);

            glVertex2i(-y+h, k+x);
            glVertex2i(-y+h, k-x);

            glVertex2i(-x+h, k+y);
            glVertex2i(-x+h, k-y);
        }
        glEnd();
    }
    glFlush();  // Send all output to display
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);  // Initialize the toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    // Set the display mode
    glutInitWindowSize(640, 480);   // Set windows size
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Polynomial Circle");

    glutDisplayFunc(myDisplay);

    myInit();
    glutMainLoop();

    return 1;
}
