#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 1.0);  // Green color
    glLineWidth(3.0f);

    glBegin(GL_LINES);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, 0.5f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("2D Line");

    glClearColor(0.1, 0.1, 0.1, 1.0);  // Dark gray background
    gluOrtho2D(-1, 1, -1, 1);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
