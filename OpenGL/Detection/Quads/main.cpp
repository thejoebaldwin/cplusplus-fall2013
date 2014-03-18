//if you get build errors:
//	right click math.h and select "open document"
//  right click the math.h tab and select "open containing folder"
//  take the "glut.h" file in the root of this project and copy into directory just opened



#include <math.h>
#include <stdio.h>
#include <iostream>
#include <glut.h>
#include <string>
#include <fstream>

#include "Cube.h"
#include "Collection.h"
#include "Helper.h"

using namespace std;

/* GLfloat arrays to specify colors */ 
static GLfloat red[]     = {1.0, 0.0, 0.0, 1.0};
static GLfloat green[]   = {0.0, 1.0, 0.0, 1.0};
static GLfloat blue[]    = {0.0, 0.0, 1.0, 1.0};
static GLfloat yellow[]  = {1.0, 1.0, 0.0, 1.0}; 
static GLfloat white[]  = {1.0, 1.0, 1.0, 1.0}; 
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
	


	if (key == 'x')
	{
		viewer[0] += 0.5;
	}
	if (key == 'X')
	{
		viewer[0] -= 0.5;
	}

	if (key == 'y')
	{
		viewer[1] += 0.5;
	}
	if (key == 'Y')
	{
		viewer[1] -= 0.5;
	}

	if (key == 'z')
	{
		viewer[2] += 0.5;
	}
	if (key == 'Z')
	{
		viewer[2] -= 0.5;
	}
	
	if (key == 'a')
	{
		light_one[0] += 0.5;
		glutPostRedisplay();
	}
	if (key == 'A')
	{
		light_one[0] -= 0.5;
		glutPostRedisplay();
	}

		if (key == 'b')
	{
		light_one[1] += 0.5;
		glutPostRedisplay();
	}
	if (key == 'B')
	{
		light_one[1] -= 0.5;
		glutPostRedisplay();
	}


		if (key == 'c')
	{
		light_one[2] += 0.5;
		glutPostRedisplay();
	}
	if (key == 'C')
	{
		light_one[2] -= 0.5;
		glutPostRedisplay();
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
   

   Quad::Colors shape[5][5] = {
	   {Quad::NONE, Quad::GREEN, Quad::RED, Quad::GREEN, Quad::NONE},
	   {Quad::GREEN, Quad::RED, Quad::GREEN, Quad::RED, Quad::GREEN},
	   {Quad::RED, Quad::GREEN, Quad::RED, Quad::GREEN, Quad::RED},
	   {Quad::GREEN, Quad::RED, Quad::GREEN, Quad::RED, Quad::GREEN},
	   {Quad::NONE, Quad::GREEN, Quad::RED, Quad::GREEN, Quad::NONE},
   };

   GLfloat offset = 1.1f;
   for (int i = 0; i < 5; i++)
   {
	   for (int j = 0; j < 5; j++)
	   {
		   if (shape[i][j] != Quad::NONE)
		   {
		    cubes.add(Cube(i * offset, j * offset, 1, shape[i][j]));
		   }
	   }
   }

   //cubes.sort();

   Collection<int> numbers(0);

   Collection<int> numbers2(0);
   Collection<int> numbers3(0);

   numbers2.add(999);
   numbers2.add(999);

   numbers.add(5);
   numbers.add(55);
   numbers.add(15);
   numbers.add(2);


   
   numbers3 = numbers + numbers2;

   cout << "Numbers:" << numbers;
   cout << "Numbers3:" << numbers3;


   //numbers.sort();
   //cout << numbers;

 

   //scratch code

   ifstream read_file("shape.txt");
   if (read_file.is_open())
   {
	  int i = 0;
	  while(read_file.good())
	  {
		  string line;
		  getline(read_file, line);
		  //cout << line << endl;
		  Collection<string> temp_words(0);
		  temp_words = Helper::Split(line,',');
		 // cout << "Line #" << i << temp_words << endl;
		  i++;
	  }

   }
   else
   {
	   cout << "There was a problem opening the file" << endl;
   }

   //string phrase = "a,lot,of,words";
   //Collection<string> words(0);
   //words = Helper::Split(phrase, ',');
   //cout << "Words:" << words;





   //Collection<string> more_words(0);
   //more_words = words;

   //words = Helper::Split("xxx,yyy,zzz", ',');

   
   //cout << "More Words:" << more_words;
}


void mouse(int button, int state, int x, int y)
{
	if (state == GLUT_UP)
	{
		
		cout << "x:" << x << " y:" << y << endl;
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