#include <math.h>
#include <stdio.h>
#include <iostream>
#include <glut.h>


using namespace std;


class Quad
{
private:
	GLfloat x_;
	GLfloat y_;
	GLfloat height_;
	GLfloat color_[4];
	

public:
	enum Colors {RED, GREEN, BLUE, YELLOW};
	Quad(GLfloat, GLfloat, GLfloat, Colors);
	void Draw();

};


Quad::Quad(GLfloat x, GLfloat y, GLfloat height, Colors color)
{
	static GLfloat red[]     = {1.0, 0.0, 0.0, 1.0};
	static GLfloat green[]   = {0.0, 1.0, 0.0, 1.0};
	static GLfloat blue[]    = {0.0, 0.0, 1.0, 1.0};
	static GLfloat yellow[]  = {1.0, 1.0, 0.0, 1.0}; 

	x_ = x;
	y_ = y;
	height_ = height;

	switch (color)
	{
	case RED:
		color_[0]    = red[0];
		color_[1]    = red[1];
		color_[2]    = red[2];
		color_[3]    = red[3];
		break;
	case GREEN:
		color_[0]    = green[0];
		color_[1]    = green[1];
		color_[2]    = green[2];
		color_[3]    = green[3];
		break;
	case BLUE:
		color_[0]    = blue[0];
		color_[1]    = blue[1];
		color_[2]    = blue[2];
		color_[3]    = blue[3];
		break;
	case YELLOW:
		color_[0]    = yellow[0];
		color_[1]    = yellow[1];
		color_[2]    = yellow[2];
		color_[3]    = yellow[3];
		break;

	}
	
	 
}

void Quad::Draw()
{
	  glBegin(GL_TRIANGLES);
       glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color_);
	   
	   glVertex3f(x_,y_,0);
	   glVertex3f(x_ + height_,y_ + height_,0);
       glVertex3f(x_ + height_,y_,0);

	   glVertex3f(x_,y_,0);
	   glVertex3f(x_,y_ + height_,0);
	   glVertex3f(x_ + height_,y_ + height_,0);

     glEnd();
}