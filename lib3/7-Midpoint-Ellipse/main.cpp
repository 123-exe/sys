#include <windows.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

const int screenWidth = 640 * 2;
const int screenHeight = 480 * 2;
GLdouble A, B, C, D; // values for scaling and shifting

void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);  // background color is white
    glColor3f(0.0f, 0.0f, 0.0f);       // drawing color is black
    glPointSize(4.0);                  // a dot is 4 by 4 pixels

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    A = screenWidth / 4.0;
    B = 0.0;
    C = D = screenHeight / 2.0;

    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT); // clear the screen
    glPointSize(2.0);

    GLint h = 300, k = 300, x, y, a = 150, b = 25;

    x = 0;
    y = b;
    int aa = a * a, bb = b * b, aa2 = aa * 2, bb2 = bb * 2;
    int fx = 0, fy = aa2 * b;
    int p = bb - aa * b + 0.25 * aa;

    while (fx < fy)
    {
        glBegin(GL_POINTS);
        glVertex2i(x + h, y + k);
        glVertex2i(-x + h, -y + k);
        glVertex2i(-x + h, y + k);
        glVertex2i(x + h, -y + k);
        glEnd();

        x++;
        fx = fx + bb2;

        if (p < 0)
            p = p + fx + bb;
        else
        {
            y--;
            fy = fy - aa2;
            p = p + fx + bb - fy;
        }
    }

    glBegin(GL_POINTS);
    glVertex2i(x + h, y + k);
    glVertex2i(-x + h, -y + k);
    glVertex2i(-x + h, y + k);
    glVertex2i(x + h, -y + k);
    glEnd();

    p = bb * (x + 0.5) * (x + 0.5) + aa * (y - 1) * (y - 1) - aa * bb;

    while (y > 0)
    {
        y--;
        fy = fy - aa2;
        if (p >= 0)
            p = p - fy + aa;
        else
        {
            x++;
            fx = fx + bb2;
            p = p + fx - fy + aa;
        }

        glBegin(GL_POINTS);
        glVertex2i(x + h, y + k);
        glVertex2i(-x + h, -y + k);
        glVertex2i(-x + h, y + k);
        glVertex2i(x + h, -y + k);
        glEnd();
    }

    glFlush(); // send all output to display
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);                        // initialize the toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // set the display mode
    glutInitWindowSize(640, 480);                 // set window size
    glutInitWindowPosition(100, 150);             // set window position
    glutCreateWindow("Midpoint Ellipse Drawing"); // open window

    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();

    return 0;
}
