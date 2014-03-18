

#include <math.h>
#include <stdio.h>
#include <iostream>
#include <glut.h>
using namespace std;

/* GLfloat arrays to specify colors */ 
static GLfloat red[]     = {1.0, 0.0, 0.0, 1.0};
static GLfloat green[]   = {0.0, 1.0, 0.0, 1.0};
static GLfloat blue[]    = {0.0, 0.0, 1.0, 1.0};
static GLfloat yellow[]  = {1.0, 1.0, 0.0, 1.0}; 

void write_message();
void init();
void reshape(int, int);
void display();
void keyboard(unsigned char, int, int);

//position of light
static GLfloat light_one[] = {0.5,    0.0, 30.0, 5.0};
// position of viewer 
static GLdouble viewer[] = {0.0, -2.0, 20.0}; 


void display()
{
   /*start boiler*/
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glLoadIdentity(); 
   //set camera direction and position
   gluLookAt(viewer[0], viewer[1], viewer[2], 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
   //draw light source
   glLightfv(GL_LIGHT0, GL_POSITION, light_one);
   /*end boiler*/


   //yellow triangle
   glBegin(GL_TRIANGLES);
       glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, yellow);
	   glVertex3f(-10,0,0);
	   glVertex3f(-10,-5,0);
       glVertex3f(-5,-5,0);
   glEnd();

   //red triangle
   glBegin(GL_TRIANGLES);
       glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, red);
	   glVertex3f(-5,0,0);
	   glVertex3f(-5,-5,0);
       glVertex3f(0,0,0);
   glEnd();

   //green triangle
    glBegin(GL_TRIANGLES);
       glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, green);
	   glVertex3f(0,0,0);
	   glVertex3f(5,-5,0);
       glVertex3f(5,0,0);
   glEnd();

   //blue triangle
    glBegin(GL_TRIANGLES);
       glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blue);
	   glVertex3f(5,-5,0);
	   glVertex3f(10,-5,0);
       glVertex3f(10,0,0);
   glEnd();

   /*start boiler*/
   glFlush();
   glutSwapBuffers();
   /*end boiler*/
}


void keyboard(unsigned char key, int x, int y)
{
   //user interaction here
}


//output in initial console
void write_message()
{
   //any control instructions go here
   cout << "OpenGL Demo" << endl;
}

//allows for resizing
void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(45.0, (GLfloat) w / (GLfloat) h, 2.0, 100.0);
   glMatrixMode(GL_MODELVIEW);
}


void init() 
{
   write_message(); 
   //"Background" color = white
   glClearColor(1.0, 1.0, 1.0, 1.0);
   glShadeModel(GL_SMOOTH);
   glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
      /* GL_FILL, GL_LINE to show wireframe */
   glEnable(GL_DEPTH_TEST);
   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
}



int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize(1280, 700); 
   glutInitWindowPosition(50, 50);
   glutCreateWindow(argv[0]);
   init();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape); 
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}