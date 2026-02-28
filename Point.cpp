#include <GL/glut.h>   // GLUT library for windowing and OpenGL utilities

/*
    display()
    -----------
    This function is responsible for rendering the scene.
    It is called automatically whenever the window needs to be redrawn.
*/
void display() {

    // Clear the screen using the color defined in glClearColor()
    glClear(GL_COLOR_BUFFER_BIT);

    /*
        Set the drawing color using RGB model.
        Values range from 0.0 to 1.0
        (1,0,0)   -> Red
        (0,1,0)   -> Green
        (0,0,1)   -> Blue
        (1,1,1)   -> White
        (0,0,0)   -> Black
    */
    glColor3f(1.0f, 0.0f, 0.0f);   // Red color

    /*
        Set point size in pixels.
        Default size is 1.0
        Try different sizes like:
        5.0f, 10.0f, 20.0f ...
    */
    glPointSize(10.0f);

    /*
        Start defining primitives.
        GL_POINTS -> Draw individual points.

        Other possible cases:
        GL_LINES
        GL_TRIANGLES
        GL_QUADS
        GL_POLYGON
    */
    glBegin(GL_POINTS);

    /*
        Define point position using 2D coordinates (x, y)

        Current coordinate system:
        gluOrtho2D(-1, 1, -1, 1)

        That means:
        Left   = -1
        Right  =  1
        Bottom = -1
        Top    =  1

        (0,0) is the center of the window.
    */
    glVertex2f(0.0f, 0.0f);   // Draw point at center

    /*
        You can draw multiple points like this:

        glVertex2f(0.5f, 0.5f);     // Top-right
        glVertex2f(-0.5f, 0.5f);    // Top-left
        glVertex2f(-0.5f, -0.5f);   // Bottom-left
        glVertex2f(0.5f, -0.5f);    // Bottom-right
    */

    glEnd();   // End primitive definition

    /*
        Force execution of OpenGL commands.
        Used with single buffering (GLUT_SINGLE).

        If using double buffering:
        Replace glFlush() with glutSwapBuffers()
    */
    glFlush();
}


/*
    main()
    -------
    Program entry point.
*/
int main(int argc, char** argv) {

    // Initialize GLUT library
    glutInit(&argc, argv);

    /*
        Set display mode:

        GLUT_SINGLE -> Single buffer
        GLUT_DOUBLE -> Double buffer (for animation)
        GLUT_RGB    -> RGB color mode
        GLUT_RGBA   -> RGB + Alpha channel
    */
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Set window size (width, height)
    glutInitWindowSize(500, 500);

    // Create window with title
    glutCreateWindow("Simple 2D Point");

    /*
        Set background color using RGBA.
        Values range from 0 to 1.

        (0,0,0,1) -> Black
        (1,1,1,1) -> White
    */
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    /*
        Define 2D orthographic projection.
        Parameters:
        gluOrtho2D(left, right, bottom, top)

        gluOrtho2D(-10, 10, -10, 10); // Larger virtual space
    */
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    // Register display callback function
    glutDisplayFunc(display);

    // Start the main loop (keeps the window open)
    glutMainLoop();

    return 0;
}