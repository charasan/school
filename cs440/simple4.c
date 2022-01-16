/* simple.c */

#include <GL/glut.h>

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);

// glPointSize is one of the few functions that does NOT go between glBegin and glEnd
  glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(-0.5, -0.5);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glVertex2f(-0.5, -0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(-0.5, 0.5);
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
