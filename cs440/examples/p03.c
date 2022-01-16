
/*
  p3.c: OpenGL program 3, compile with command "glutcc p3"

  -- changes field of view, still just 2D graphics.
     see the last three statements in the program.
*/

#include <stdio.h>
#include <GL/glut.h>

#define X 800
#define Y 600

void display();

main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
  glutInitWindowSize(X,Y);

  glutCreateWindow("First OpenGL Program");
  glutDisplayFunc(display);

  mystuff();

  glutMainLoop();
}
void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POLYGON);
    glVertex2f( 0.0, 1.0);
    glVertex2f( 1.0,-1.0);
    glVertex2f(-1.0,-1.0);
  glEnd();
  glFlush();
}
mystuff()
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glColor3f(1.0, 0.0, 0.0);
/*
  the next three lines change the area shown on the display.
  instead of just showing a large enough area to cover the
  triangle (the default), we show the square with opposite
  corners (-2,2) and (2,-2).

  the first lines are opengl hocus-pocus that initializes
  what is called a "transformation matrix".  the third line
  specifies the area of the plane to display.
*/
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-2.0, 2.0, 2.0, -2.0);
}
