//if you get build errors:
//	right click math.h and select "open document"
//  right click the math.h tab and select "open containing folder"
//  take the "glut.h" file in the root of this project and copy into directory just opened



#include <math.h>
#include <stdio.h>
#include <iostream>
#include <glut.h>
#include <string>

#include "Cube.h"
#include "Collection.h"

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
void draw();
void keyboard(unsigned char, int, int);

//position of light
static GLfloat light_one[] = {0.5,    0.0, 30.0, 5.0};
// position of viewer 
static GLdouble viewer[] = {0.0, -2.0, 20.0}; 

GLfloat x_inc = 0;

Collection<Cube> cubes(0);

GLfloat offset = 0;

void draw()
{
	for (int i = 0; i < cubes.length() ; i++)
	{
	  cubes[i].Draw();
	  cubes[i].move();
	}
}

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
   
   draw();

   /*start boiler*/
   glFlush();
   glutSwapBuffers();
   glutPostRedisplay();
   /*end boiler*/
}


void keyboard(unsigned char key, int x, int y)
{
   //user interaction here
	
	if (key == 'a')
	{
		viewer[0] -= 0.5;
		cout << "User Pressed A Key" << endl;
	}
	if (key == 's')
	{
		viewer[0] += 0.5;
		cout << "User Pressed S Key" << endl;
	}
	if (key == 'w')
	{
		viewer[1] += 0.5;
	}
	if (key == 'z')
	{
		viewer[1] -= 0.5;
	}

	if (key == '-')
	{
		viewer[2] += 0.5;
	}
	if (key == '=')
	{
		viewer[2] -= 0.5;
	}
	
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
   glClearColor(0.0, 0.0, 0.0, 1.0);
   glShadeModel(GL_SMOOTH);
   glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
   glEnable(GL_DEPTH_TEST);
   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   
   cubes.add(Cube(0, 0, 1, Quad::RED));
   cubes.add(Cube(2, 0, 1, Quad::BLUE));
   cubes.add(Cube(4, 0, 1, Quad::GREEN));

}


void mouse(int button, int state, int x, int y)
{
	if (state == GLUT_UP)
	{
		
		GLfloat winX = (GLfloat) x;//point.x and point.y are the mouse coordinates
		GLfloat winY = (GLfloat)viewer[3] - (GLfloat) y;


	    Cube c(winX, winY, 1, Quad::RED);
		cubes.add(c);
	}
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
   glutMouseFunc(mouse);
   glutMainLoop();
   return 0;
}