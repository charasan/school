/* square.c */
#define DEG_TO_RAD 57.29578
#include <GL/glut.h>
#include <math.h>

GLfloat theta = 0.0;

void mydisplay()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(cos(DEG_TO_RAD *theta), sin(DEG_TO_RAD *theta));
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(-sin(DEG_TO_RAD *theta), cos(DEG_TO_RAD *theta));
	glColor3f(1.0, 0.0, .06);
	glVertex2f(-cos(DEG_TO_RAD *theta), -sin(DEG_TO_RAD *theta));
	glColor3f(1.0, 0.0, .06);
	glVertex2f(sin(DEG_TO_RAD *theta), -cos(DEG_TO_RAD *theta));
  glEnd();
//  glFlush();
  glutSwapBuffers();
}

void mykey(char key)
{
// Quit if the user pushes 'Q', 'q', or the escape key
  if(key == 'q' || key == 'Q' || key == '\27')
    exit(0);
}

void myidle()
{
  theta += 2.0;
  if(theta >= 360.0) theta -= 360.0;
  glutPostRedisplay();
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutCreateWindow("Chapter 3");
  glutDisplayFunc(mydisplay);
  glutMainLoop();
}
