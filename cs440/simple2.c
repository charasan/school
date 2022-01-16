/* simple.c */

#include <GL/glut.h>

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_POLYGON);
	glVertex2f(-0.7, -0.7);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.7, 0.7);
	glVertex2f(0.5, -0.5);
  glEnd();

  glFlush();
}

void init()
{
// Sets the clear color to black
  glClearColor(0.0, 0.0, 0.0, 0.0);
// Sets the fill color to white
  glColor3f(1.0, 1.0, 1.0);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("simple");
  glutDisplayFunc(display);
  init();
  glutMainLoop();
}
