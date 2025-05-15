#include<windows.h>
#include<math.h>
#include<GL/glut.h>

void midpointline(int x1, int y1, int x2, int y2)
{
    int dx, dy, dE, dNE;
    dx=x2-x1;
    dy=y2-y1;
    float d=dy-dx/2;
    dE=dy;
    dNE=dy-dx;
    int x=x1, y=y1;
    glVertex2f(x, y);
    while(x<x2)
    {
        if(d<=0)
        {
            d = d+dE;
            ++x;
        }
        else
        {
            d = d+dNE;
            ++x; ++y;
        }
        glVertex2f(x,y);
    }
    glVertex2f(x2,y2);
}
void RenderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 0.0f); // Line Color
    glPointSize(3);
    glBegin(GL_POINTS);
    midpointline(100, 100, 400, 400); // Line Position
    glEnd();
    glFlush();
}
void ChangeSize(GLsizei w, GLsizei h)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // White Background
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, 500.0f, 0.0f, 500.0f, -1.0f, 1.0f); // Line Position
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200,200);
    glutCreateWindow("Midpoint Line");
    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);
    glutMainLoop();
    return 1;
}
