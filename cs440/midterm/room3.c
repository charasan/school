/*
 * OpenGL program by Eddie Fuller
 * A 3-D room populated by a series of teapots.
 *   User can turn right or left, and move backwards or forwards
 *   Black/red checkboard texture for floor, ambient lighting
 *   Brass lighting material on teapots, with ambient light source in room
 */
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

#define checkImageWidth 64
#define checkImageHeight 64

static float angle=0.0, ratio;
static float x=0.0, y=1.75, z=5.0;
static float lx=0.0, ly=0.0, lz=-1.0;
static GLint teapotList;
static GLubyte checkImage[checkImageHeight][checkImageWidth][4];
static GLuint texName;

void output(GLfloat x, GLfloat y, char *format,...)
{
  va_list args;
  char buffer[200], *p;

  va_start(args, format);
  vsprintf(buffer, format, args);
  va_end(args);
  glPushMatrix();
  glTranslatef(x, y, 0);
  for (p = buffer; *p; p++)
    glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
  glPopMatrix();
}

void makeCheckImage(void)
{
   int i, j, c;
    
   for (i = 0; i < checkImageHeight; i++)
  {
      for (j = 0; j < checkImageWidth; j++)
      {
         c = ((((i&0x4)==0)^((j&0x4))==0))*255;
         checkImage[i][j][0] = (GLubyte) c;
         checkImage[i][j][1] = (GLubyte) 0;
         checkImage[i][j][2] = (GLubyte) 0;
         checkImage[i][j][3] = (GLubyte) 255;
      }
   }
}

void reshape(int w, int h)
{
  ratio = 1.0 * w / h;

  // Set the viewport to be the entire window
  glViewport(0, 0, (GLsizei) w, (GLsizei) h);
  // Reset the coordinate system before modifying
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // Set the clipping volume
  gluPerspective(45,ratio,1,1000);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(x, y, z, x + lx,y + ly,z + lz, 0.0, 1.0, 0.0);
}

void drawTeapots()
{
  GLfloat brass_ambient[]   = {0.33, 0.22, 0.03, 1.0};
  GLfloat brass_diffuse[]     = {0.78, 0.57, 0.11, 1.0};
  GLfloat brass_specular[]  = {0.99, 0.91, 0.81, 1.0};
  GLfloat brass_shininess[] = { 27.8 };
  GLfloat light_position[]     = {1.0, 0.0, 1.0, 0.0};
  
  glColor3f(1.0, 1.0, 1.0);

// Draw Body	
  glTranslatef(0.0 , 0.75, 0.0);
  glMaterialfv(GL_FRONT, GL_AMBIENT, brass_ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, brass_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, brass_specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, brass_shininess);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  glutSolidTeapot(.5);

}

GLuint createDL() 
{
  GLuint teapotDL;
  // Create the id for the list
  teapotDL = glGenLists(1);
  // start list
  glNewList(teapotDL,GL_COMPILE);
  // call the function that contains the rendering commands
  drawTeapots();
  // endList
  glEndList();
  return(teapotDL);
}

void initScene()
{
  glClearColor (0.0, 0.0, 0.0, 0.0);
  glShadeModel (GL_SMOOTH);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  
  glEnable(GL_DEPTH_TEST);
  makeCheckImage();
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

  glGenTextures(1, &texName);
  glBindTexture(GL_TEXTURE_2D, texName);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth, checkImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, checkImage);
  teapotList = createDL();
}

// Total Eclipse of the Heart
void turnAround(float ang)
{
  lx = sin(ang);
  lz = -cos(ang);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0, 1.0, 0.0);
}


void bookit(int i)
{
  float prevx = x;
  float prevz = z;

  x = x + i*(lx)*0.2;
  z = z + i*(lz)*0.2;

  if( ( (x+lx) > 99.0 || (x +lx) < -99.0) || (z+lz) > 99.0 || (z+lz) < -99.0)
  {
	return;
  }

  else
  {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0, 1.0, 0.0);
  }
}

void processNormalKeys(unsigned char key, int x, int y)
{
  if (key == 27) 
	exit(0);
}


void inputKey(int key, int x, int y)
{
  switch (key)
  {
	case GLUT_KEY_LEFT :
		angle -= 0.05;
		turnAround(angle);
		break;
	case GLUT_KEY_RIGHT : 
		angle +=0.05;
		turnAround(angle);
		break;
	case GLUT_KEY_UP : 
		bookit(1);
		break;
	case GLUT_KEY_DOWN : 
		bookit(-1);
		break;
  }
}

void display(void)
{
  int i, j = -3;
  GLfloat slate_ambient[]   = {0.02, 0.02, 0.02};
  GLfloat slate_diffuse[]     = {0.02, 0.01, 0.01};
  GLfloat slate_specular[]  = {0.4, 0.4, 0.4};
  GLfloat slate_shininess[] = { .78125 };
  GLfloat light_position[] = { 1.0, 0.8, 0.0, 0.0 };
  
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_TEXTURE_2D);
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
  glBindTexture(GL_TEXTURE_2D, texName);
  // Draw ground
  glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-100.0, 0.0, -100.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(-100.0, 0.0,  100.0);
	glTexCoord2f(1.0, 1.0); glVertex3f( 100.0, 0.0,  100.0);
	glTexCoord2f(1.0, 0.0); glVertex3f( 100.0, 0.0, -100.0);
  glEnd();

    // Draw ceiling (in case we add an option to look up
  glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-100.0, 100.0, -100.0);
	glTexCoord2f(0.0, 1.0); glVertex3f( 100.0, 100.0, -100.0);
	glTexCoord2f(1.0, 1.0); glVertex3f( 100.0, 100.0,  100.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(-100.0, 100.0,  100.0);
  glEnd();
  glDisable(GL_TEXTURE_2D);

// Draw walls
  glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, slate_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, slate_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, slate_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, slate_shininess);
	  glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(-100.0, 100.0, -100.0);
		glTexCoord2f(0.0, 1.0); glVertex3f( 100.0, 100.0, -100.0);
		glTexCoord2f(1.0, 1.0); glVertex3f( 100.0,     0.0, -100.0);
		glTexCoord2f(1.0, 0.0); glVertex3f(-100.0,     0.0, -100.0);
	  glEnd();
   glPopMatrix();
  
   glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, slate_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, slate_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, slate_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, slate_shininess);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(-100.0, 100.0, -100.0);
		glTexCoord2f(0.0, 1.0); glVertex3f(-100.0, 100.0,  100.0);
		glTexCoord2f(1.0, 1.0); glVertex3f(-100.0,     0.0,  100.0);
		glTexCoord2f(1.0, 0.0); glVertex3f(-100.0,     0.0, -100.0);
	glEnd();
  glPopMatrix();
  
  glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, slate_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, slate_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, slate_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, slate_shininess);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f( 100.0, 100.0, -100.0);
		glTexCoord2f(0.0, 1.0); glVertex3f( 100.0, 100.0,  100.0);
		glTexCoord2f(1.0, 1.0); glVertex3f( 100.0,     0.0,  100.0);
		glTexCoord2f(1.0, 0.0); glVertex3f( 100.0,    0.0, -100.0);
	glEnd();
  glPopMatrix();
  
  glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, slate_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, slate_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, slate_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, slate_shininess);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(-100.0, 100.0,  100.0);
		glTexCoord2f(0.0, 1.0); glVertex3f( 100.0, 100.0,  100.0);
		glTexCoord2f(1.0, 1.0); glVertex3f( 100.0,     0.0,  100.0);
		glTexCoord2f(1.0, 0.0); glVertex3f(-100.0,     0.0,  100.0);
	glEnd();
  glPopMatrix();

  glFlush();

// Add 36 teapots to the scene
  for(i = -3; i < 3; i++)
	for(j=-3; j < 3; j++)
	{
		glPushMatrix();
		glTranslatef(i*10.0,0,j * 10.0);
		glCallList(teapotList); // Use the display list
		glPopMatrix();
	}
  glutSwapBuffers();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(640,360);
  glutCreateWindow("A Very Merry Un-Birthday To Me");
  initScene();
  glutKeyboardFunc(processNormalKeys);
  glutSpecialFunc(inputKey);
  glutDisplayFunc(display);
  glutIdleFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();
  return(0);
}
