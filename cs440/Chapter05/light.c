#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

static GLdouble spin = 0.0;

void init(void) 
{
   GLfloat mat_specular[]   = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat mat_shininess[]  = { 50.0 };
/* Ambient, Diffuse, and Specular are color related to the light
 * Ambient light is a soft light with no discernable source - also refers to intensity of ambient light that source gives the scene
 * Diffuse light is focused, like a spotlight, and bounces equally in all directions - defines the color light gives to a scene
 * Specular light is directed, and bounces in a preferred direction - laser-like, also effects "shiny spots" on things like glass
 */
   GLfloat light_ambient[]  = { 1.0, 0.0, 0.0, 1.0 };
   GLfloat light_diffuse[]  = { 1.0, 1.0, 0.0, 1.0 };
   GLfloat light_specular[] = { 0.0, 1.0, 1.0, 1.0 };
   GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
   GLfloat light1_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat light1_diffuse[] = { 0.5, 0.5, 0.0, 1.0 };
   GLfloat light1_specular[] = { 1.0, 0.0, 1.0, 1.0 };
   GLfloat light1_position[] = { -2.0, 2.0, 1.0, 1.0 };
   GLfloat spot_direction[]  = { -1.0, -1.0, 0.0 };

   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_SMOOTH);

   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
   glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
   glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
   glLightfv(GL_LIGHT0, GL_POSITION, light_position);

   glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
   glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
   glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);
   glLightfv(GL_LIGHT1, GL_POSITION, light1_position);

   glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 2.0);
   glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 1.0);
   glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.5);
   glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.5);
   glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.5);
   glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.2);

   glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0);
   glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
   glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.0);

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_LIGHT1);
   glEnable(GL_DEPTH_TEST);
}

void display(void)
{
   GLfloat light_position[] = { 0.0, 0.0, 1.5, 1.0 };
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   glPushMatrix();
      gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
      glPushMatrix();
         glRotated(spin, 1.0, 0.0, 0.0);
         glLightfv(GL_LIGHT2, GL_POSITION, light_position);
      glPopMatrix();
      glutSolidTorus( 0.275, 0.85, 8, 15);
   glPopMatrix();
   glFlush ();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();
   if (w <= h)
      glOrtho (-1.5, 1.5, -1.5*(GLfloat)h/(GLfloat)w,
         1.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
   else
      glOrtho (-1.5*(GLfloat)w/(GLfloat)h,
         1.5*(GLfloat)w/(GLfloat)h, -1.5, 1.5, -10.0, 10.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutMainLoop();
   return 0;
}
