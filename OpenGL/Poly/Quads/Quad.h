#include <math.h>
#include <stdio.h>
#include <iostream>
#include <glut.h>

using namespace std;

#ifndef QUAD_H
#define QUAD_H

class Quad
{
protected:
	GLfloat x_;
	GLfloat y_;
	GLfloat height_;
	GLfloat color_[4];
	GLfloat x_speed_;
	GLfloat y_speed_;
	GLfloat x_pos_;
	GLfloat y_pos_;
	GLfloat angle_;
	GLfloat rotation_;
	


public:
	enum Colors {RED, GREEN, BLUE, YELLOW, WHITE};
	Quad();
	Quad(GLfloat, GLfloat, GLfloat, Colors);
	void Draw();
	void set_x(GLfloat);
	void set_y(GLfloat);
	GLfloat x();
	GLfloat y();
	void move();
	void set_x_speed(GLfloat);
	void set_y_speed(GLfloat);
	void set_rotation(GLfloat);
	void set_color(Colors);

};

Quad::Quad()
{
	 Quad(0,0,10,RED);  
}

void Quad::set_color(Colors color)
{
	static GLfloat red[]     = {1.0, 0.0, 0.0, 1.0};
	static GLfloat green[]   = {0.0, 1.0, 0.0, 1.0};
	static GLfloat blue[]    = {0.0, 0.0, 1.0, 1.0};
	static GLfloat yellow[]  = {1.0, 1.0, 0.0, 1.0}; 
	static GLfloat white[]  = {1.0, 1.0, 1.0, 1.0}; 


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
			case WHITE:
		color_[0]    = white[0];
		color_[1]    = white[1];
		color_[2]    = white[2];
		color_[3]    = white[3];
		break;

	}
}


Quad::Quad(GLfloat x, GLfloat y, GLfloat height, Colors color)
{

	x_pos_ = x;
	y_pos_ = y;
	height_ = height;

	x_speed_ = 0;
	y_speed_ = 0;
	
	angle_ = 0;
	rotation_ = 0;

    set_color(color);	 
}

void Quad::Draw()
{

	 GLfloat half_height = height_ / 2.0f;


	 glPushMatrix();
	 
	 glTranslatef(x_pos_, y_pos_, 0);
	  glRotatef(angle_, 0.0f, 0.0f, 1.0f);
	  

	   glBegin(GL_TRIANGLES);
       glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color_);
	   
	   glVertex3f(-half_height, -half_height,0);
	   glVertex3f(half_height, half_height,0);
       glVertex3f(half_height, -half_height,0);

	   glVertex3f(-half_height, -half_height,0);
	   glVertex3f(-half_height,half_height,0);
	   glVertex3f(half_height, half_height,0);

     glEnd();

	 glPopMatrix();
}

	void Quad::set_x(GLfloat x)
	{
		x_pos_ = x;
	}
	
	void Quad::set_y(GLfloat y)
	{
		y_pos_ = y;
	}

	GLfloat Quad::x()
	{
		return x_;
	}
	
	GLfloat Quad::y()
	{
		return y_;
	}
		
	void Quad::move()
	{
		x_pos_ = x_pos_ + x_speed_;
		y_pos_ = y_pos_ + y_speed_;
		angle_ += rotation_;
	}
	
	void Quad::set_x_speed(GLfloat x_speed)
	{
		x_speed_ = x_speed;
	}

	void Quad::set_y_speed(GLfloat y_speed)
	{
		y_speed_ = y_speed;
	}

	void Quad::set_rotation(GLfloat rotation)
	{
		rotation_ = rotation;
	}

#endif /* QUAD_H */
