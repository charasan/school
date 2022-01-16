
/*
  p4.c: OpenGL program 4, compile with command "glutcc p4"

  -- draw lines and points, instead of a polygon
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
  glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);  /* select red */
    glVertex2f( 0.0, 0.0);  /* start of line 1 */
    glVertex2f( 1.0, 1.0);  /* end of line 1 */
    glColor3f(0.0, 1.0, 0.0);  /* select green */
    glVertex2f( 0.0, 0.0);  /* start of line 2 */
    glVertex2f( 1.0,-1.0);  /* etc. */
    glColor3f(0.0, 0.0, 1.0);  /* select blue */
    glVertex2f(-1.0, 0.0);
    glVertex2f( 0.0, 0.0);
  glEnd();
  glBegin(GL_POINTS);
    glColor3f(1.0, 1.0, 0.0);  /* select yellow */
    glVertex2f( 0.5, 0.2);   /* add some points */
    glVertex2f( 0.4, 0.7);
    glVertex2f( 0.3, 0.8);
    glVertex2f( 0.6, 0.1);
  glEnd();
  glFlush();
}
mystuff()
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glColor3f(1.0, 0.0, 0.0);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-2.0, 2.0, 2.0, -2.0);
}
