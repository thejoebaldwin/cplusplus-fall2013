#include "Quad.h"

class Ghost
{
private:
	static const int ghost_length_ = 21;
	Quad ghost_[ghost_length_] ;
	GLfloat angle_;
public:
	Ghost();
	void set_rotation(GLfloat);
	void set_x_speed(GLfloat);
	void draw();
	void move();
};

Ghost::Ghost()
{
				   ghost_[0] =Quad(0,0,1, Quad::WHITE);
				   ghost_[1] =Quad(1,0,1, Quad::WHITE);
				   ghost_[2] =Quad(2,0,1, Quad::WHITE);
				   ghost_[3] =Quad(3,0,1, Quad::WHITE);
				   ghost_[4] =Quad(4,0,1, Quad::WHITE);
					   
				   ghost_[5] =Quad(0,-1,1, Quad::WHITE);
				   ghost_[6] =Quad(2,-1,1, Quad::WHITE);
				   ghost_[7] =Quad(4,-1,1, Quad::WHITE);

				   ghost_[8] =Quad(0,-2,1, Quad::WHITE);
				   ghost_[9] =Quad(1,-2,1, Quad::WHITE);
				   ghost_[10] =Quad(2,-2,1, Quad::WHITE);
				   ghost_[11] =Quad(3,-2,1, Quad::WHITE);
				   ghost_[12] =Quad(4,-2,1, Quad::WHITE);

				   ghost_[13] =Quad(0,-3,1, Quad::WHITE);
				   ghost_[14] =Quad(1,-3,1, Quad::WHITE);
				   ghost_[15] =Quad(2,-3,1, Quad::WHITE);
				   ghost_[16] =Quad(3,-3,1, Quad::WHITE);
				   ghost_[17] =Quad(4,-3,1, Quad::WHITE);

				   ghost_[18] =Quad(0,-4,1, Quad::WHITE);
				   ghost_[19] =Quad(2,-4,1, Quad::WHITE);
				   ghost_[20] =Quad(4,-4,1, Quad::WHITE);

				   angle_ = 0;
}


void Ghost::set_rotation(GLfloat rotate)
{
	for (int i = 0; i < ghost_length_; i++)
		{
			ghost_[i].set_rotation(rotate);
		}
}

void Ghost::set_x_speed(GLfloat x_speed)
{
	for (int i = 0; i < ghost_length_; i++)
		{
			ghost_[i].set_x_speed(x_speed);
		}
}

void Ghost::move()
{
   for (int i = 0; i < ghost_length_; i++)
   {
	ghost_[i].move();
   }
   angle_ += 0.01;
}

void Ghost::draw()
{

	 glPushMatrix();
	 
	 //glTranslatef(x_pos_, y_pos_, 0);
	  glRotatef(angle_, 0.0f, 0.0f, 1.0f);

   for (int i = 0; i < ghost_length_; i++)
   {
	ghost_[i].Draw();
   }

   glPopMatrix();


}