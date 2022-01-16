
/*
  p2.c: OpenGL program 2, compile with command "glutcc p2"
*/

#include <stdio.h>
#include <GL/glut.h>

#define X 800
#define Y 600

void display();

main(int argc, char *argv[])
{
  glutInit(&argc, argv);
/*
  The next two lines are new.  The first one
  doesn't change anything, because it sets
  two modes that are already the defaults:
  RGB color mode (the default way to specify colors),
  and single buffer mode (also the default).  The
  other buffer mode possibility is double buffer mode.
  Double buffering allows you to have two copies of the
  screen display, the "old" one and the "new" one.
  The idea is to allow you to finish the new one before you
  display it, so the change looks instantaneous.  More on
  this later.
*/
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
}
