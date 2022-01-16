#include <GL/glut.h>

// vertex coords array

GLfloat vertices[] = {1,1,1,  -1,1,1,  -1,-1,1,  1,-1,1,        // v0-v1-v2-v3
                      1,1,1,  1,-1,1,  1,-1,-1,  1,1,-1,        // v0-v3-v4-v5
                      1,1,1,  1,1,-1,  -1,1,-1,  -1,1,1,        // v0-v5-v6-v1
                      -1,1,1,  -1,1,-1,  -1,-1,-1,  -1,-1,1,    // v1-v6-v7-v2
                      -1,-1,-1,  1,-1,-1,  1,-1,1,  -1,-1,1,    // v7-v4-v3-v2
                      1,-1,-1,  -1,-1,-1,  -1,1,-1,  1,1,-1};   // v4-v7-v6-v5

// normal array
GLfloat normals[] = {0,0,1,  0,0,1,  0,0,1,  0,0,1,             // v0-v1-v2-v3
                     1,0,0,  1,0,0,  1,0,0, 1,0,0,              // v0-v3-v4-v5
                     0,1,0,  0,1,0,  0,1,0, 0,1,0,              // v0-v5-v6-v1
                     -1,0,0,  -1,0,0, -1,0,0,  -1,0,0,          // v1-v6-v7-v2
                     0,-1,0,  0,-1,0,  0,-1,0,  0,-1,0,         // v7-v4-v3-v2
                     0,0,-1,  0,0,-1,  0,0,-1,  0,0,-1};        // v4-v7-v6-v5

// color array
GLfloat colors[] = {1,1,1,  1,1,0,  1,0,0,  1,0,1,              // v0-v1-v2-v3
                    1,1,1,  1,0,1,  0,0,1,  0,1,1,              // v0-v3-v4-v5
                    1,1,1,  0,1,1,  0,1,0,  1,1,0,              // v0-v5-v6-v1
                    1,1,0,  0,1,0,  0,0,0,  1,0,0,              // v1-v6-v7-v2
                    0,0,0,  0,0,1,  1,0,1,  1,0,0,              // v7-v4-v3-v2
                    0,0,1,  0,0,0,  0,1,0,  0,1,1};             // v4-v7-v6-v5

// index array of vertex array for glDrawElements()
// Notice the indices are listed straight from beginning to end as exactly
// same order of vertex array without hopping, because of different normals at
// a shared vertex. For this case, glDrawArrays() and glDrawElements() have no
// difference.
GLubyte indices[] = {0,1,2,3,
                     4,5,6,7,
                     8,9,10,11,
                     12,13,14,15,
                     16,17,18,19,
                     20,21,22,23};

void draw1()
{
    glPushMatrix();
    glTranslatef(-2, 2, 0); // move to upper left corner
    glBegin(GL_QUADS);
        // face v0-v1-v2-v3
        glNormal3f(0,0,1);
        glColor3f(1,1,1);
        glVertex3f(1,1,1);
        glColor3f(1,1,0);
        glVertex3f(-1,1,1);
        glColor3f(1,0,0);
        glVertex3f(-1,-1,1);
        glColor3f(1,0,1);
        glVertex3f(1,-1,1);

        // face v0-v3-v4-v6
        glNormal3f(1,0,0);
        glColor3f(1,1,1);
        glVertex3f(1,1,1);
        glColor3f(1,0,1);
        glVertex3f(1,-1,1);
        glColor3f(0,0,1);
        glVertex3f(1,-1,-1);
        glColor3f(0,1,1);
        glVertex3f(1,1,-1);

        // face v0-v5-v6-v1
        glNormal3f(0,1,0);
        glColor3f(1,1,1);
        glVertex3f(1,1,1);
        glColor3f(0,1,1);
        glVertex3f(1,1,-1);
        glColor3f(0,1,0);
        glVertex3f(-1,1,-1);
        glColor3f(1,1,0);
        glVertex3f(-1,1,1);

        // face  v1-v6-v7-v2
        glNormal3f(-1,0,0);
        glColor3f(1,1,0);
        glVertex3f(-1,1,1);
        glColor3f(0,1,0);
        glVertex3f(-1,1,-1);
        glColor3f(0,0,0);
        glVertex3f(-1,-1,-1);
        glColor3f(1,0,0);
        glVertex3f(-1,-1,1);

        // face v7-v4-v3-v2
        glNormal3f(0,-1,0);
        glColor3f(0,0,0);
        glVertex3f(-1,-1,-1);
        glColor3f(0,0,1);
        glVertex3f(1,-1,-1);
        glColor3f(1,0,1);
        glVertex3f(1,-1,1);
        glColor3f(1,0,0);
        glVertex3f(-1,-1,1);

        // face v4-v7-v6-v5
        glNormal3f(0,0,-1);
        glColor3f(0,0,1);
        glVertex3f(1,-1,-1);
        glColor3f(0,0,0);
        glVertex3f(-1,-1,-1);
        glColor3f(0,1,0);
        glVertex3f(-1,1,-1);
        glColor3f(0,1,1);
        glVertex3f(1,1,-1);
    glEnd();

    glPopMatrix();
}

void draw2()
{
    // enble and specify pointers to vertex arrays
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    glNormalPointer(GL_FLOAT, 0, normals);
    glColorPointer(3, GL_FLOAT, 0, colors);
    glVertexPointer(3, GL_FLOAT, 0, vertices);

    glPushMatrix();
    glTranslatef(2, 2, 0);                  // move to upper-right

    glDrawArrays(GL_QUADS, 0, 24);

    glPopMatrix();

    glDisableClientState(GL_VERTEX_ARRAY);  // disable vertex arrays
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
}

void draw3()
{
    // enable and specify pointers to vertex arrays
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    glNormalPointer(GL_FLOAT, 0, normals);
    glColorPointer(3, GL_FLOAT, 0, colors);
    glVertexPointer(3, GL_FLOAT, 0, vertices);

    glPushMatrix();
    glTranslatef(-2, -2, 0);                // move to bottom-left

    glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, indices);

    glPopMatrix();

    glDisableClientState(GL_VERTEX_ARRAY);  // disable vertex arrays
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
}

void draw4()
{
    // enable and specify pointers to vertex arrays
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    glNormalPointer(GL_FLOAT, 0, normals);
    glColorPointer(3, GL_FLOAT, 0, colors);
    glVertexPointer(3, GL_FLOAT, 0, vertices);

    glPushMatrix();
    glTranslatef(2, -2, 0);                 // move to bottom-right

    // draw first half (12 elements) {0,1,2,3, 4,5,6,7, 8,9,10,11}
    // tell the driver we use vertices from index 0 to index 11, which means 11-0+1 = 12 vertices
    // So, the driver can prefetch an amount of 12 vertex data prior to rendering
    glDrawRangeElements(GL_QUADS, 0, 11, 12, GL_UNSIGNED_BYTE, indices);

    // draw last half (12 elements) {12,13,14,15, 16,17,18,19, 20,21,22,23}
    // tell the driver we use vertices from index 12 to index 23, which means 23-12+1 = 12 vertices
    // So, the driver can prefetch an amount of 12 vertex data prior to rendering
    glDrawRangeElements(GL_QUADS, 12, 23, 12, GL_UNSIGNED_BYTE, indices + 12);

    glPopMatrix();

    glDisableClientState(GL_VERTEX_ARRAY);  // disable vertex arrays
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
}
