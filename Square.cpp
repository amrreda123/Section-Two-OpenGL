#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.3);
    // glPointSize(10.0f);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    /*
        glPolygonMode(face, mode)
        face: GL_FRONT, GL_BACK, GL_FRONT_AND_BACK
        mode:
                GL_POINT => Point mode,
                GL_LINE => Wireframe mode, 
                GL_FILL => Solid mode
    */
    // glLineWidth(2.0f);
    // glBegin(GL_LINE_STRIP); not closed
    // glBegin(GL_LINE_LOOP);
    glBegin(GL_QUADS);
    glVertex2f(-0.3f, -0.3f);   // left-bottom
    glVertex2f(-0.3f, 0.3f);   // left-top
    glVertex2f(0.3f, 0.3f);   // right-top
    glVertex2f(0.3f, -0.3f); // right-bottom
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("2D Square");

    glClearColor(0.0, 0.0, 0.0, 1.0);  
    gluOrtho2D(-1, 1, -1, 1);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
