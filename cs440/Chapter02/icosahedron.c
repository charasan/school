/* simple.c */

#include <GL/glut.h>
#define X .525731112119133606 
#define Z .850650808352039932

void display()
{
  static GLfloat vdata[12][3] = {    
     {-X, 0.0, Z}, {X, 0.0, Z}, {-X, 0.0, -Z}, {X, 0.0, -Z},    
     {0.0, Z, X}, {0.0, Z, -X}, {0.0, -Z, X}, {0.0, -Z, -X},    
     {Z, X, 0.0}, {-Z, X, 0.0}, {Z, -X, 0.0}, {-Z, -X, 0.0} 
  };
  static GLuint tindices[20][3] = { 
     {0,4,1}, {0,9,4}, {9,5,4}, {4,5,8}, {4,8,1},    
     {8,10,1}, {8,3,10}, {5,3,8}, {5,2,3}, {2,7,3},    
     {7,10,3}, {7,6,10}, {7,11,6}, {11,0,6}, {0,1,6}, 
     {6,1,10}, {9,0,11}, {9,11,2}, {9,2,5}, {7,2,11} };

  int i;

  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_TRIANGLES);    
  for (i = 0; i < 20; i++) {    
     /* color information here */ 
     glVertex3fv(&vdata[tindices[i][0]][0]); 
     glVertex3fv(&vdata[tindices[i][1]][0]); 
     glVertex3fv(&vdata[tindices[i][2]][0]); 
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
