#include <iostream>
#include <iomanip>
#include <conio.h>
#include "Point.h"

using namespace std;

int main()
{
	cout << "hello" << endl;
	int i = 47;
	Point p;
	p.set_latitude(44.2656);
	p.set_longitude(88.4017);

	Point p2(Point::random_latitude(), Point::random_longitude());
	
	Point p3 = Point::random_point();

	cout << "Point lat,lon:" << p3.latitude() 
		<< "," << p3.longitude() << endl;


	_getch();



	return 0;
}
