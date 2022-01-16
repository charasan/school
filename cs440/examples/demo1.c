
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <GL/glut.h>

#define WID 500
#define HGT 500
#define X   162
#define Y   134 

typedef struct roadsign {
  GLfloat pos;
  GLfloat dx;
} SIGN;

void display();
void reshape(int w, int h);
void keyboard(unsigned char c, int x, int y);
void special_keyboard(int key, int x, int y);
void drive();
void makeRasterFont(void);

double ph = 1.0;

GLfloat pos[4] = {0.00,  1.25, 1.00, 1.00};
GLfloat dir[4] = {0.00, -1.00, 5.00, 1.00};

GLfloat white[4]   = {0.7, 0.7, 0.7, 1.0};
GLfloat lgray[4]   = {0.5, 0.5, 0.5, 1.0};
GLfloat dgray[4]   = {0.3, 0.3, 0.3, 1.0};
GLfloat black[4]   = {0.1, 0.1, 0.1, 1.0};
GLfloat yellow[4]  = {0.8, 0.8, 0.1, 1.0};
GLfloat green[4]   = {0.1, 0.4, 0.1, 1.0};

GLfloat lightdir[] = {0.0,-0.1,-1.0, 1.0};

GLfloat dist =  0.0;

#define NPOSTS 5

SIGN post[NPOSTS];

main(int argc, char *argv[])
{
  srand48(time(0));

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(WID,HGT);
  glutInitWindowPosition(X,Y);
  glutCreateWindow("September 30, 2001");

  initposts();
  initlighting();

  glutDisplayFunc(display);
  glutIdleFunc(drive);
  glutKeyboardFunc(keyboard);
  glutSpecialFunc(special_keyboard);
  glutReshapeFunc(reshape);

  glutMainLoop();
}
void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  glPushMatrix();
  drawroad();
  glutSwapBuffers();
  glPopMatrix();
}
void reshape(int w, int h)
{
  glViewport(0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(120.0, 1.0, 0.01, 30.0);
  glMatrixMode(GL_MODELVIEW);
}
void keyboard(unsigned char c, int x, int y)
{
  switch(c){
    case  27: exit(0);
    case 'h': pos[0] += 0.1; break;
    case 'l': pos[0] -= 0.1; break;
    default:
      break;
  }
  glutPostRedisplay();
}
void special_keyboard(int key, int x, int y)
{
   switch(key) {
     case GLUT_KEY_LEFT:
       pos[0] += 0.1;
       break;
     case GLUT_KEY_RIGHT:
       pos[0] -= 0.1;
       break;
   }
}
void drive()
{
  usleep(1000);
  dist += 0.1;
  ph -= 0.1;
  if(ph < 0.0) ph += 1.0;
  glutPostRedisplay();
}
drawroad()
{
  GLfloat x,y,z;
  int i;

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();
  glLightfv(GL_LIGHT0, GL_POSITION, pos);
  glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, lightdir);
  gluLookAt(pos[0], pos[1], pos[2],
            pos[0]+dir[0], pos[1]+dir[1], pos[2]+dir[2],
               0.0,    1.0,    0.0);
  glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,dgray);
  glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,lgray);
  glBegin(GL_POLYGON);
    glNormal3f( 0.0, 1.0,  0.0);
    glVertex3f( 1.0, 0.0, 50.0);
    glNormal3f( 0.0, 1.0,  0.0);
    glVertex3f(-1.0, 0.0, 50.0);
    glNormal3f( 0.0, 1.0,  0.0);
    glVertex3f(-1.0, 0.0,-50.0);
    glNormal3f( 0.0, 1.0,  0.0);
    glVertex3f( 1.0, 0.0,-50.0);
  glEnd();
  glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,green);
  glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,green);
  glBegin(GL_POLYGON);
    glNormal3f( 0.0, 1.0,  0.0);
    glVertex3f( 1.0, 0.0, 50.0);
    glNormal3f( 0.0, 1.0,  0.0);
    glVertex3f( 5.0,-0.5, 50.0);
    glNormal3f( 0.0, 1.0,  0.0);
    glVertex3f( 5.0,-0.5,  0.0);
    glNormal3f( 0.0, 1.0,  0.0);
    glVertex3f( 1.0, 0.0,  0.0);
  glEnd();
  glBegin(GL_POLYGON);
    glNormal3f( 0.0, 1.0,  0.0);
    glVertex3f(-1.0, 0.0, 50.0);
    glNormal3f( 0.0, 1.0,  0.0);
    glVertex3f(-5.0,-0.5, 50.0);
    glNormal3f( 0.0, 1.0,  0.0);
    glVertex3f(-5.0,-0.5,  0.0);
    glNormal3f( 0.0, 1.0,  0.0);
    glVertex3f(-1.0, 0.0,  0.0);
  glEnd();
#if 1
  glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,yellow);
  glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,yellow);
  for(z = 0.0; z < 25.0 ; z += 1.0){
    glBegin(GL_POLYGON);
      glNormal3f( 0.0, 1.0,  0.0);
      glVertex3f( 0.1, 0.1, ph+z);
      glNormal3f( 0.0, 1.0,  0.0);
      glVertex3f( 0.1, 0.1, ph+z+0.25);
      glNormal3f( 0.0, 1.0,  0.0);
      glVertex3f(-0.1, 0.1, ph+z+0.25);
      glNormal3f( 0.0, 1.0,  0.0);
      glVertex3f(-0.1, 0.1, ph+z);
    glEnd();
  }
#endif
  glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,lgray);
  glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);
  for(i=0;i<NPOSTS;i++){
    if(post[i].pos > dist){
      glPushMatrix();
      glTranslatef(post[i].dx, 0.0, post[i].pos-dist);
      glBegin(GL_QUADS);
        glNormal3f(0.0,0.1,1.0);
        glVertex3f(-0.4,0.5,0.0);
        glNormal3f(0.0,0.1,1.0);
        glVertex3f(-0.4,1.5,0.0);
        glNormal3f(0.0,0.1,1.0);
        glVertex3f( 0.4,1.5,0.0);
        glNormal3f(0.0,0.1,1.0);
        glVertex3f( 0.4,0.5,0.0);
      glEnd();
      glPopMatrix();
    } else {
      randpost(i);
    }
  }
  glPopMatrix();
}
initlighting()
{
  glEnable(GL_DEPTH_TEST);
  glLightfv(GL_LIGHT0, GL_POSITION, pos);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);

  glLightfv(GL_LIGHT0, GL_AMBIENT, dgray);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, lgray);
  glLightfv(GL_LIGHT0, GL_SPECULAR,white);

  glLightf (GL_LIGHT0, GL_SPOT_CUTOFF, 30.0);
  glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, lightdir);

  glEnable(GL_FOG);
  glFogi(GL_FOG_MODE, GL_EXP);
  glFogfv(GL_FOG_COLOR, black);
  glFogf(GL_FOG_DENSITY, 0.2);
  glFogf(GL_FOG_HINT,GL_DONT_CARE);
  glFogf(GL_FOG_START, 0.5);
  glFogf(GL_FOG_END,  50.0);
}
randpost(int n)
{
  post[n].pos = dist + 10.0 + 50.0*drand48();
  post[n].dx = (lrand48() % 100 < 50) ? 2.0 : -2.0;
}
initposts()
{
  int i;

  for(i=0;i<NPOSTS;i++)
    randpost(i);
}
