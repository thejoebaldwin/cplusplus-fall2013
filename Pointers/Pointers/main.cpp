#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

int growByOne(int*, int);

int main()
{
	
	
	int* numbers = new int[5];
	int* more_numbers = new int[10];
	
	numbers[0] = 5;
	numbers[1] = 6;
	numbers[2] = 7;
	numbers[3] = 8;
	numbers[4] = 9;
	//more_numbers[0] = 99;

	
	numbers = growByOne(numbers, 5);

	cout << numbers[5];


	_getch();
	return 1;
}

int* growByOne(int* myarray, int myarray_length)
{
	//declare new array one larger
	int* new_array = new int[myarray_length + 1];
	//copy old values into new array
	for (int i = 0; i < myarray_length; i++)
	{
		new_array[i] = myarray[i];
	}
	new_array[myarray_length] = 0;
	//return new array
	return new_array;
}

void pointers()
{
	int i = 5;
	int* p = new int;
	*p = 6; 
	cout << "int i:" << i << endl;
	cout << "&i:" << &i << endl;
	cout << "int* p:" << p << endl;
	cout << "*p:" << *p << endl;
	cout << "&p:" << &p << endl;
	p = &i;
	i = 99;
	cout << "p after &i:" << p << endl;
	cout << "*p after &i:" << *p << endl;
}