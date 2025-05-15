#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0); // Set background color to black
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0); // Set 2D orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void draw_triangle(void)
{
    glBegin(GL_LINE_LOOP); // Draw triangle outline
    glVertex2f(0.0, 25.0);
    glVertex2f(25.0, -25.0);
    glVertex2f(-25.0, -25.0);
    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);      // Set drawing color to white

    glLoadIdentity();              // Draw original triangle
    draw_triangle();

    glEnable(GL_LINE_STIPPLE);

    glLineStipple (1, 0xF0F0);
    glLoadIdentity ();
    glTranslatef (-20.0, 0.0, 0.0);  // Translate triangle 20 units left along the X-axis
    draw_triangle ();

    glLineStipple(1, 0xF0F0);
    glLoadIdentity();
    glRotatef(45.0, 0.0, 0.0, 1.0);  // Apply 2D rotation (about Z-axis)
    draw_triangle();

    glDisable(GL_LINE_STIPPLE);
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);                   // Set window size
    glutInitWindowPosition(100, 100);               // Set window position
    glutCreateWindow("Translation and Rotation");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
