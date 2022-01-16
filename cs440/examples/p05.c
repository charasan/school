
/*
  p5.c: OpenGL program 5, compile with command "glutcc p5"

  -- very simple animation, uses double buffering
*/

#include <stdio.h>
#include <GL/glut.h>

#define X 800
#define Y 600

void display();
void moveline();

double a[2],b[2];  /* array to store end points of a line */

main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);  /* note change */
  glutInitWindowSize(X,Y);

  glutCreateWindow("First OpenGL Program");
  glutDisplayFunc(display);

 /*
  tell OpenGL to execute the "moveline" function when
  there's nothing else to do.  this is where the
  animation happens.
*/

  glutIdleFunc(moveline);

  mystuff();

  glutMainLoop();
}
void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_LINES);
    glVertex2f(a[0],a[1]);
    glVertex2f(b[0],b[1]);
  glEnd();
  glutSwapBuffers();
}
void moveline()
{
  usleep(1000);  /* slow thing down by sleep of 1/1000 sec */
  a[1] -= 0.01;
  b[1] -= 0.01;
  if(a[1] < -1.0)
    a[1] = b[1] = 1.0;
  glutPostRedisplay();  /* call display function */
}
mystuff()
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glColor3f(1.0, 0.0, 0.0);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-2.0, 2.0, 2.0, -2.0);

  a[0] = -1.0;
  a[1] =  1.0;
  b[0] =  1.0;
  b[1] =  1.0;
}
