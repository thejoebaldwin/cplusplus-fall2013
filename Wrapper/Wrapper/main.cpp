#include <iostream>
#include <conio.h>
#include "Collection.h"

using namespace std;

int main()
{
	Collection<double> c(0);
	//c[0]= 22;
	c.add(12.34);
	c.add(56.78);
	c.add(91.01);
	c.add(234.56);
	
	cout << c << endl;

	_getch();

	return 0;
}
