/* simple.c */

#include <GL/glut.h>

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glPolygonMode(GL_FRONT, GL_FILL);
  glPolygonMode(GL_BACK, GL_LINE);
  glEnable(GL_CULL_FACE);
  glCullFace(GL_FRONT);

  glBegin(GL_POLYGON);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.0, 3.0);
        glVertex2f(4.0, 3.0);
	glVertex2f(6.0, 1.5);
	glVertex2f(4.0, 0.0);
  glEnd();

  glBegin(GL_POLYGON);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.0, -4.0);
	glVertex2f(-4.0, -5.5);
	glVertex2f(-6.0, -7.0);
	glVertex2f(-4.0, 0.0);
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
  gluOrtho2D(-10.0, 10.0, -10.0, 10.0);

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
