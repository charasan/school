
/*
  p1.c: OpenGL program 1, compile with command "glutcc p1"
 
  -- 2 dimensional graphics
*/

#include <stdio.h>
#include <GL/glut.h>

void display();

main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutCreateWindow("First OpenGL Program");
/*
  register function to call to create stuff to display
*/
  glutDisplayFunc(display);

  mystuff();

  glutMainLoop();
}
void display()
{
  glClear(GL_COLOR_BUFFER_BIT); /* clears display buffer */
  glBegin(GL_POLYGON);          /* make a triangle */
    glVertex2f( 0.0, 1.0);
    glVertex2f( 1.0,-1.0);
    glVertex2f(-1.0,-1.0);
  glEnd();
  glFlush();                    /* send display buffer to physical display */
}
mystuff()
{
/*
  set background color ("clearcolor") to black
*/
  glClearColor(0.0, 0.0, 0.0, 0.0);
/*
  select red (RGB = <1,0,0>) for drawing, parameters must be floats
*/
  glColor3f(1.0, 0.0, 0.0);
}
