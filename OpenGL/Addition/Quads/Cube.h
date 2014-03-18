#include "Quad.h"


class Cube : public Quad
{
private:

public:
	void Draw();
	Cube();
	Cube(GLfloat, GLfloat, GLfloat, Colors);
	friend bool operator>(Cube&,Cube&);
};

Cube::Cube()
{
	Cube(0,0,10,RED);
}

Cube::Cube(GLfloat x, GLfloat y, GLfloat height, Colors color)
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


void Cube::Draw()
{
	static GLfloat red[]     = {1.0, 0.0, 0.0, 1.0};
	static GLfloat green[]   = {0.0, 1.0, 0.0, 1.0};
	static GLfloat blue[]    = {0.0, 0.0, 1.0, 1.0};
	static GLfloat yellow[]  = {1.0, 1.0, 0.0, 1.0}; 
	static GLfloat white[]  = {1.0, 1.0, 1.0, 1.0}; 


	 GLfloat half_height = height_ / 2.0f;


	 glPushMatrix();
	 
	 glTranslatef(x_pos_, y_pos_, 0);
	  glRotatef(angle_, 0.0f, 0.0f, 1.0f);
	  

	   glBegin(GL_TRIANGLES);

	

       glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color_);
	      
	   //front face
	   glVertex3f(-half_height, -half_height,half_height);
	   glVertex3f(half_height, half_height,half_height);
       glVertex3f(half_height, -half_height,half_height);

	   glVertex3f(-half_height, -half_height,half_height);
	   glVertex3f(-half_height,half_height,half_height);
	   glVertex3f(half_height, half_height,half_height);

	   //back face
	   glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color_);
	   glVertex3f(-half_height, -half_height,-half_height);
	   glVertex3f(half_height, half_height,-half_height);
       glVertex3f(half_height, -half_height,-half_height);

	   glVertex3f(-half_height, -half_height,-half_height);
	   glVertex3f(-half_height,half_height,-half_height);
	   glVertex3f(half_height, half_height,-half_height);

	   //top
	   glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color_);
	   glVertex3f(-half_height, half_height,-half_height);
	   glVertex3f(half_height, half_height,half_height);
       glVertex3f(half_height, half_height,-half_height);

	   glVertex3f(-half_height, half_height,-half_height);
	   glVertex3f(-half_height,half_height,half_height);
	   glVertex3f(half_height, half_height,half_height);

	   //bottom
	   glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color_);
	   glVertex3f(-half_height, -half_height,-half_height);
	   glVertex3f(half_height, -half_height,half_height);
       glVertex3f(half_height, -half_height,-half_height);

	   glVertex3f(-half_height, -half_height,-half_height);
	   glVertex3f(-half_height,-half_height,half_height);
	   glVertex3f(half_height, -half_height,half_height);
	   //left
	    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color_);
	   glVertex3f(-half_height, -half_height,-half_height);
	   glVertex3f(-half_height, half_height,half_height);
       glVertex3f(-half_height, -half_height,half_height);

	   glVertex3f(-half_height, -half_height,-half_height);
	   glVertex3f(-half_height,half_height,-half_height);
	   glVertex3f(-half_height, half_height,half_height);
	   //right
	     glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color_);
	   glVertex3f(half_height, -half_height,-half_height);
	   glVertex3f(half_height, half_height,half_height);
       glVertex3f(half_height, -half_height,half_height);

	   glVertex3f(half_height, -half_height,-half_height);
	   glVertex3f(half_height,half_height,-half_height);
	   glVertex3f(half_height, half_height,half_height);

     glEnd();

	 glPopMatrix();
}


bool operator> (Cube &c1, Cube &c2)
{
	return c1.color_ > c2.color_;
}