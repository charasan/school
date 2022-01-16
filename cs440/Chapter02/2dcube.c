/* simple.c */

#include <GL/glut.h>

void display()
{
  GLubyte allIndices[] = {4, 5, 6, 7, 1, 2, 6, 5, 
   0, 1, 5, 4, 0, 3, 2, 1, 
   0, 4, 7, 3, 2, 3, 7, 6};

  glClear(GL_COLOR_BUFFER_BIT);

  glEnableClientState(GL_VERTEX_ARRAY);
  glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, allIndices);
  glDisableClientState(GL_VERTEX_ARRAY);
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
  glutCreateWindow("2D Cube");
  glutDisplayFunc(display);
  init();
  glutMainLoop();
}
