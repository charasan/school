/* simple.c */

#include <GL/glut.h>

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);

  static GLint vertices[] = {25, 25,
                            100, 325,
                            175, 25,
                            175, 325,
                            250, 25,
                            325, 325};
  static GLfloat colors[] = {1.0, 0.2, 0.2,
                            0.2, 0.2, 1.0,
                            0.8, 1.0, 0.2,
                            0.75, 0.75, 0.75,
                            0.35, 0.35, 0.35,
                            0.5, 0.5, 0.5};

  glEnableClientState (GL_COLOR_ARRAY);
  glEnableClientState (GL_VERTEX_ARRAY);
  glColorPointer (3, GL_FLOAT, 0, colors);
  glVertexPointer (2, GL_INT, 0, vertices);

  glBegin(GL_TRIANGLES);
	glArrayElement (2);
	glArrayElement (3);
	glArrayElement (5);
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
  glutCreateWindow("Vertex Arrays");
  glutDisplayFunc(display);
  init();
  glutMainLoop();
}
