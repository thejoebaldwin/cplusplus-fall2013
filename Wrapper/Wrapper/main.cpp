#include <iostream>
#include <conio.h>
#include "Collection.h"

using namespace std;

int main()
{
	Collection c(0);
	c[0]= 22;
	c.add(99);
	c.add(77);
	c.add(66);
	c.add(200);
	
	cout << c << endl;

	_getch();

	return 0;
}
