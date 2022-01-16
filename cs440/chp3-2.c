/* simple.c */
#include <stdlib.h>
#include <GL/glut.h>

typedef int bool;

#define FALSE 0
#define TRUE (-1)

GLint x1, z1, x2, z2;
int hh;

void mymouse(int x, int y, int button, int state)
{
  static bool first = TRUE;
  int x1, z1;
  if(state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)
    exit(0);
  if(state == GLUT_DOWN && button == GLUT_RIGHT_BUTTON)
  {
    if(first)
    {
      x1 = x;
      z1 = hh - y;
      first = !first;
    }
    else
    {
      first = !first;
      x2 = x;
      z2 = hh - y;
    }
    glutPostRedisplay();
  }
}

void mydisplay()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POLYGON);
	glVertex2i(x1, z1);
	glVertex2i(x1, hh - z2);
	glVertex2i(x2, hh - z2);
	glVertex2i(x2, z1);
  glEnd();
  glFlush();
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutCreateWindow("Chapter 3");
  glutDisplayFunc(mydisplay);
  glutMouseFunc(mymouse);
  glutMainLoop();
}
