#include <GL/glut.h>
#include <math.h>

#define DEG_TO_RAD 57.29578 /* degrees to radian */
GLfloat theta = 0.0;

void mydisplay()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POLYGON);
    glVertex2f(cos(DEG_TO_RAD *theta), sin(DEG_TO_RAD *theta));
    glVertex2f(-sin(DEG_TO_RAD *theta), cos(DEG_TO_RAD *theta));
    glVertex2f(-cos(DEG_TO_RAD *theta), -sin(DEG_TO_RAD *theta));
    glVertex2f(sin(DEG_TO_RAD *theta), -cos(DEG_TO_RAD *theta));
  glEnd();
  glFlush();
}
void myidle()
{
  theta += 2.0;
  if(theta >= 360.0) theta -= 360.0;
  glutPostRedisplay();
}


