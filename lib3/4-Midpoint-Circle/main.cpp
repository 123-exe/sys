#include<windows.h>
#include<math.h>
#include<GL/glut.h>

void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);  // Background Color is White
    glColor3f(0.0f, 0.0f, 0.0f);  // Drawing Color is Black
    glPointSize(4.0);  // A dot is 2 by 2 pixel

    // Initialize View (Simple Orthographic Projection)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    // Set The Viewing Coordinates
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void Draw(int x, int y, int xC, int yC)
{
    glBegin(GL_POINTS);
    {
        glVertex2i(xC + x, yC + y);
        glVertex2i(xC + x, yC - y);

        glVertex2i(xC - x, yC + y);
        glVertex2i(xC - x, yC - y);

        glVertex2i(xC + y, yC + x);
        glVertex2i(xC - y, yC + x);

        glVertex2i(xC + y, yC - x);
        glVertex2i(xC - y, yC - x);

    }
    glEnd();
}

void Circle(int Radius, int xC, int yC)
{
    int P, x, y;

    P = 1 - Radius;
    x = 0;
    y = Radius;

    while(x<=y)
    {
        x++;

        if(P < 0)
            P = P + 2 * x + 3;

        else
        {
            P = P + 2 * (x - y) + 5;
            y--;
        }

        Draw(x, y, xC, yC);
    }
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);  // Clear The Screen
    glPointSize(2.0);

    Circle(150, 320, 240);
    glFlush();
    // Send All Output to Display
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);  // Initialize The Toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // Set The Display Mode
    glutInitWindowSize(640, 480);  // Set Window Size
    // Set Window Position on Screen
    glutInitWindowPosition(10, 15);
    // Open The Screen Window & Set The Name
    glutCreateWindow("Midpoint Circle");

    glutDisplayFunc(myDisplay);

    myInit();

    glutMainLoop(); // Go Into a Perpetual Loop

    return 1;
}
