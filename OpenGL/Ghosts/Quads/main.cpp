//if you get build errors:
//	right click math.h and select "open document"
//  right click the math.h tab and select "open containing folder"
//  take the "glut.h" file in the root of this project and copy into directory just opened



#include <math.h>
#include <stdio.h>
#include <iostream>
#include <glut.h>
#include "Quad.h"

using namespace std;

/* GLfloat arrays to specify colors */ 
static GLfloat red[]     = {1.0, 0.0, 0.0, 1.0};
static GLfloat green[]   = {0.0, 1.0, 0.0, 1.0};
static GLfloat blue[]    = {0.0, 0.0, 1.0, 1.0};
static GLfloat yellow[]  = {1.0, 1.0, 0.0, 1.0}; 




Quad ghost[25] = {
					   Quad(0,0,1, Quad::WHITE),
					   Quad(1,0,1, Quad::WHITE),
					   Quad(2,0,1, Quad::WHITE),
					   Quad(3,0,1, Quad::WHITE),
					   Quad(4,0,1, Quad::WHITE),
					   
					   Quad(0,-1,1, Quad::WHITE),
					   Quad(2,-1,1, Quad::WHITE),
					   Quad(4,-1,1, Quad::WHITE),

					   Quad(0,-2,1, Quad::WHITE),
					   Quad(1,-2,1, Quad::WHITE),
					   Quad(2,-2,1, Quad::WHITE),
					   Quad(3,-2,1, Quad::WHITE),
					   Quad(4,-2,1, Quad::WHITE),

					      Quad(0,-3,1, Quad::WHITE),
					   Quad(1,-3,1, Quad::WHITE),
					   Quad(2,-3,1, Quad::WHITE),
					   Quad(3,-3,1, Quad::WHITE),
					   Quad(4,-3,1, Quad::WHITE),

					   Quad(0,-4,1, Quad::WHITE),
					   Quad(2,-4,1, Quad::WHITE),
					   Quad(4,-4,1, Quad::WHITE),

	
	
};

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
Quad q(1 + x_inc, 1, 3, Quad::RED);

Quad q2(0.25f + x_inc, 0.33f, 1, Quad::BLUE);

void draw()
{

	//x_inc += 0.001;
	 //q.set_x(q.x() + 0.1);
	

	
   for (int i = 0; i < 25; i++)
   {
	ghost[i].move();
	ghost[i].Draw();
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
	if (key == 'k')
	{
		   for (int i = 0; i < 25; i++)
   {
	ghost[i].set_rotation(1);
	
   }
	}
	if (key == 'l')
	{
		for (int i = 0; i < 25; i++)
   {
	ghost[i].set_x_speed(-0.01);
	
   }

		if (key == 's')
	{
		for (int i = 0; i < 25; i++)
   {
	
	
   }
		}


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