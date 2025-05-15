#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>

void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0); // Background color is white
    glColor3f(0.0f, 0.0f, 0.0f);      // Drawing color is black
    glPointSize(2.0);                  // Points are 2x2 pixels
    glLineWidth(3.0);                  // Lines 5 pixels thick
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen

    GLint h = 200, k = 200, x, y, r, d;

    y = r = 100;
    d = 3 - 2 * r;

    for (x = 0; x <= y; x++)
    {
        glBegin(GL_POINTS);
        {
            glVertex2i(x + h, k + y);
            glVertex2i(x + h, k - y);

            glVertex2i(y + h, k + x);
            glVertex2i(y + h, k - x);

            glVertex2i(-y + h, k + x);
            glVertex2i(-y + h, k - x);

            glVertex2i(-x + h, k + y);
            glVertex2i(-x + h, k - y);
        }
        glEnd();

        if (d < 0)
            d = d + 4 * x + 6;
        else
        {
            d = d + 4 * (x - y) + 10;
            y--;
        }
    }
    glFlush(); // Send all output to display
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv); // Initialize
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set the display mode

    glutInitWindowSize(640, 480); // Set window size
    glutInitWindowPosition(100, 150); // Set window position on screen
    glutCreateWindow("Bresenham's Circle");

    glutDisplayFunc(myDisplay);

    myInit();
    glutMainLoop(); // Go into a perpetual loop

    return 0;
}
