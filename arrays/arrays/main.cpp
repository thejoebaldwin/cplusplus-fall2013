#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

int smallest(int[], int);
int sum(int[], int);
int* grow(int[], int, int);
//won't work! array degrades to pointer
int length(int numbers[]);


int main()
{
	//length of arrays
	int numbers_length = 5;
	int numbers_new_length = numbers_length + 1;
	//initialize array
	int* numbers = new int[numbers_length];
	numbers[0] = 1;
	numbers[1] = 2;
	numbers[2] = 3;
	numbers[3] = 4;
	numbers[4] = 5;

    //grow the array by 1
	numbers = grow(numbers, numbers_length, numbers_new_length);
	//output newly grown array
	for (int i = 0; i < numbers_new_length; i++)
	{
		cout << "Element " << i << ": " << numbers[i] << endl;
	}
	cout << "--------------------------------" << endl;

	//output the sum
	cout << endl << "Sum of array: " << sum(numbers, numbers_length);
	//output the smallest
	cout << endl << "Smallest Element: " << smallest(numbers, numbers_length);

	//press any key
	_getch();
	return 0;
}

//grows the array by 1
int* grow(int numbers[], int current_length, int new_length)
{
	//allocate new array
	int* numbers_new = new int[new_length];
	
	//loop through array copying old values
	for (int i = 0; i < new_length; i++)
	{
		//if less than old length copy
		if (i < current_length)
		{
			numbers_new[i] = numbers[i];
		}
		//else place default value of 0
		else
		{
			numbers_new[i] = 0;
		}
	}
	//return pointer to new array
	return numbers_new;
}

int length(int numbers[])
{
	//this does not work because array degrades into a pointer
	//	with no knowledge of total bytes allocated to array
	cout << endl << "Size of Array: " << sizeof(numbers) << " Size of Element[0]: " 
		<< sizeof(numbers[0]) << endl;
	int length =  sizeof(numbers) / sizeof(numbers[0]);
	cout << "Length of the Array: " <<length << endl;
	return length;
}

//loop through array and find the smallest value
int smallest(int numbers[], int numbers_length)
{
	int smallest = numbers[0];
	
	for (int i = 0; i < numbers_length; i++)
	{
		if (numbers[i] < smallest)
		{
			smallest = numbers[i];
		}
	}
	return smallest;
}

//loop through the array and add all values
int sum(int numbers[], int numbers_length)
{
	int total = 0;
	
	for (int i = 0; i < numbers_length; i++)
	{
		total += numbers[i];
	}
	return total;
}
