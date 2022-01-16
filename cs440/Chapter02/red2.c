/*
 * A simple 2D circle
 *  -- note: not the most efficient method of drawing circle.
 *           not recommended for drawing multiple circles, but an ok example.
 * Taken from http://www.glprogramming.com/red/chapter02.html
 */
#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926535898
GLint circle_points = 100;

void display()
{
  int i;
  float angle;

  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_LINE_LOOP);
    for(i = 0; i < circle_points; i++)
    {
      angle = 2 * PI * i/circle_points;
      glVertex2f(cos(angle), sin(angle));
    }
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
  gluOrtho2D(-5.0, 5.0, -5.0, 5.0);

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
