#include <windows.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;

// Clipping window boundaries
const int X_MIN = 100, X_MAX = 400;
const int Y_MIN = 100, Y_MAX = 400;

// Region codes
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // White background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

int computeCode(double x, double y) {
    int code = INSIDE;
    if (x < X_MIN) code |= LEFT;
    else if (x > X_MAX) code |= RIGHT;
    if (y < Y_MIN) code |= BOTTOM;
    else if (y > Y_MAX) code |= TOP;
    return code;
}

void clipAndDrawLine(double x1, double y1, double x2, double y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    bool accept = false;

    while (true) {
        if (!(code1 | code2)) { // Both endpoints inside
            accept = true;
            break;
        } else if (code1 & code2) { // Both outside same region
            break;
        } else {
            int codeOut = code1 ? code1 : code2;
            double x, y;

            // Find intersection point
            if (codeOut & TOP) {
                x = x1 + (x2 - x1) * (Y_MAX - y1) / (y2 - y1);
                y = Y_MAX;
            } else if (codeOut & BOTTOM) {
                x = x1 + (x2 - x1) * (Y_MIN - y1) / (y2 - y1);
                y = Y_MIN;
            } else if (codeOut & RIGHT) {
                y = y1 + (y2 - y1) * (X_MAX - x1) / (x2 - x1);
                x = X_MAX;
            } else if (codeOut & LEFT) {
                y = y1 + (y2 - y1) * (X_MIN - x1) / (x2 - x1);
                x = X_MIN;
            }

            if (codeOut == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    if (accept) {
        glColor3f(0.0, 0.0, 1.0); // Blue for clipped line
        glBegin(GL_LINES);
        glVertex2d(x1, y1);
        glVertex2d(x2, y2);
        glEnd();
    }
}

void drawWindow() {
    glColor3f(0.0, 0.0, 0.0); // Black for window
    glBegin(GL_LINE_LOOP);
    glVertex2i(X_MIN, Y_MIN);
    glVertex2i(X_MAX, Y_MIN);
    glVertex2i(X_MAX, Y_MAX);
    glVertex2i(X_MIN, Y_MAX);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawWindow();

    // Original lines (red)
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2i(50, 50);   glVertex2i(450, 450); // Diagonal
    glVertex2i(200, 50);  glVertex2i(200, 450); // Vertical
    glVertex2i(50, 300);  glVertex2i(450, 300); // Horizontal
    glEnd();

    // Clip and draw lines (blue)
    clipAndDrawLine(50, 50, 450, 450);
    clipAndDrawLine(200, 50, 200, 450);
    clipAndDrawLine(50, 300, 450, 300);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Cohen-Sutherland Line Clipping");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
