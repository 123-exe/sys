#include<windows.h>
#include<GL/glut.h>

void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);  // White background
    glColor3f(0.0f, 0.0f, 0.0f);       // Black drawing color
    glPointSize(1.0);                 // Pixel size

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 640.0, 0.0, 480.0, -1.0, 1.0); // 2D orthographic projection
}

void drawPixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void scanlineFill(int x1, int y1, int x2, int y2)
{
    for(int y = y1; y <= y2; y++)
    {
        for(int x = x1; x <= x2; x++)
        {
            drawPixel(x, y);
        }
    }
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Coordinates of rectangle (bottom-left and top-right)
    int x1 = 200, y1 = 150;
    int x2 = 400, y2 = 300;

    // Draw filled rectangle using scanline algorithm
    glColor3f(1.0f, 0.0f, 0.0f); // Red fill color
    scanlineFill(x1, y1, x2, y2);

    // Draw rectangle outline
    glColor3f(0.0f, 0.0f, 0.0f); // Black border color
    glBegin(GL_LINE_LOOP);
    glVertex2i(x1, y1);
    glVertex2i(x2, y1);
    glVertex2i(x2, y2);
    glVertex2i(x1, y2);
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Rectangle Fill - Scanline Algorithm");

    myInit();
    glutDisplayFunc(myDisplay);
    glutMainLoop();

    return 0;
}
