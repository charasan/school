
/*
  p6.c: OpenGL program 6, compile with command "glutcc p6"

  -- very simple animation, uses double buffering
     throw in a little trigonometry...
*/

#include <stdio.h>
#include <math.h>       /* note that this line was added */
#include <GL/glut.h>

#define X 800
#define Y 800

void display();
void moveline();

double theta;          /* the angle of the line */

main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);  /* note change */
  glutInitWindowSize(X,Y);

  glutCreateWindow("First OpenGL Program");
  glutDisplayFunc(display);

  glutIdleFunc(moveline);

  mystuff();

  glutMainLoop();
}
void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_LINES);
    glVertex2f(0.0, 0.0);
    glVertex2f(cos(theta),sin(theta));
  glEnd();
  glutSwapBuffers();
}
void moveline()
{
  usleep(1000);         /* slow thing down by sleep of 1/1000 sec */
  theta -= 0.01;        /* increase the angle */
  glutPostRedisplay();  /* call display function */
}
mystuff()
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glColor3f(1.0, 1.0, 0.0);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-2.0, 2.0, 2.0, -2.0);

  theta = 0.0;
}
