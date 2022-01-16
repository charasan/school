#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <GL/glut.h>

void display();
void moveLine();
void setItUp();

double hour, minute;
int seconds = 0;

main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutInitWindowSize(500, 500);

  glutCreateWindow("Simulated Clock");
  glutDisplayFunc(display);

  glutIdleFunc(moveLine);

  setItUp();

  glutMainLoop();
}
void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  int i;
  int sections = 40;
  GLfloat radius = 1.2f;
  GLfloat twoPi = 2.0f * 3.14159f;

  glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.1, 0.1, 0.1);
    glVertex2f(0.0, 0.0);
    for(i = 0; i <= sections;i++)
    {
      glVertex2f(radius * cos(i * twoPi / sections),
        radius* sin(i * twoPi / sections));
    }
  glEnd();

  radius = 1.1f;
  glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.6, 0.6, 0.6);
    glVertex2f(0.0, 0.0);
    for(i = 0; i <= sections;i++)
    {
      glVertex2f(radius * cos(i * twoPi / sections),
        radius* sin(i * twoPi / sections));
    }
  glEnd();

  glBegin(GL_LINES);
    glLineWidth(3);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.0, 0.0);
    glVertex2f(cos(hour)/1.3, sin(hour)/1.3);
    glLineWidth(2);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.0, 0.0);
    glVertex2f(cos(minute), sin(minute));
  glEnd();

  glutSwapBuffers();
}
void moveLine()
{
  usleep(60000);
  minute += 0.01;
  hour += 0.001;

  glutPostRedisplay();
}
void setItUp()
{
  glClearColor(0.0, 0.0, 0.0, 0.0);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-2.0, 2.0, 2.0, -2.0);

  hour = 0.0;
  minute = 0.0;
}
