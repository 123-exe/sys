#include<windows.h>
#include<GL/glut.h>

void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);  // Background Color is White
    glColor3f(0.0f, 0.0f, 0.0f);  // Drawing Color is Black
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);  // Clear The Screen
    glPointSize(2.0);
    GLint x, y, x1 = 50, x2 = 100, y1 = 100, y2 = 200;
    GLint dx, dy, inc1, inc2, d;

    x = x1;
    y = y1;

    dx = x2 - x1;
    dy = y2 - y1;

    inc1 = 2 * dy;
    inc2 = 2 * (dy - dx);

    d = inc1 - dx;

    while(x <= x2)
    {
        glBegin(GL_POINTS);
        {
            glVertex2i(x, y);
        }
        glEnd();

        x++;

        if(d < 0)
            d = d + inc1;

        else
        {
            d = d + inc2;
            y++;
        }
    }
    glFlush();  // Send All Output to Display
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);  // Initialize The Toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // Set The Display Mode
    glutInitWindowSize(640, 480);  // Set Window Size
    // Set Window Position on Screen
    glutInitWindowPosition(100, 150);
    // Open The Screen Window and Set The Name
    glutCreateWindow("Bresenham Line");

    glutDisplayFunc(myDisplay);

    myInit();
    glutMainLoop();  // Go Into a Perpetual Loop

    return 1;
}

