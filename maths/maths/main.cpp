#include <iostream>
#include <conio.h>
#include <iomanip>
//need for shell color on windows machine
#include <Windows.h>
#include <math.h>
using namespace std;

//need to declare (but not define) before use
void setConsole();

int main()
{
	//ONLY FOR MY DISPLAY
	setConsole();
  	
	//declare variables
	double num_one = 0;
	double num_two = 0;
	double num_one_squared;
	double num_two_squared;
	double num_answer;
	double num_temp = 0;

	cout << fixed << setprecision(4);

	//get input from user
	cout << "Please enter the first number: ";
	cin >> num_one;
	cout << "Please enter the second number: ";
	cin >> num_two;
	//do calculations/logic
	num_one_squared = num_one * num_one;
	num_two_squared = num_two * num_two;
	num_answer =  num_one + ((num_two / num_one) * num_two);
	num_temp = num_answer * 10;
	num_temp = ceil(num_temp);
	num_temp = num_temp / 10;

	//output to the user
	cout << "num_one: " << num_one << " num_two: " << num_two << endl;
	cout << "num_one squared: " << num_one_squared << " num_two squared: " << num_two_squared << endl;
	cout  << "num_one + num_two / num_one * num_two: " <<num_answer << endl; 
	cout << "Round Answer Up: "<< ceil(num_answer) << endl;
	cout << "Round Answer Down: "<< floor(num_answer) << endl;
	cout << "Square Root num_one: " << sqrt(num_one);
	cout << " Square Root num_two: " << sqrt(num_two) << endl;
	cout << "num_one ^ num_two: " << pow(num_one, num_two) << endl;
	cout << "num_one / num_two: " << num_one / num_two << endl;
	cout << "num_one mod num_two: " << (int) num_one % (int) num_two << endl;

	cout << "random number: " << rand() * clock() % 100 << endl;
	cout << "random number: " << rand() * clock() % 100 << endl;
	cout << "random number: " << rand() * clock() % 100 << endl;
	cout << "random number: " << rand() * clock() % 100 << endl;

	//pause for user keypress
	_getch();
	return 0;
}

void setConsole()
{
	 //color value for console
	int color = 25;  
	//console reference	
	HANDLE	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//this will loop until either 0 is entered, or a non-numeric value

   	PCONSOLE_FONT_INFOEX font = new CONSOLE_FONT_INFOEX();
   	font->cbSize = sizeof(CONSOLE_FONT_INFOEX);
   
    	//CONSOLE_FONT_INFOEX is defined in some windows header
    	GetCurrentConsoleFontEx(hConsole, false, font);
	//PCONSOLE_FONT_INFOEX is the same as CONSOLE_FONT_INFOEX*
    	font->dwFontSize.X = 10;
    	font->dwFontSize.Y = 18;
	SetCurrentConsoleFontEx(hConsole, false, font);
	SetConsoleTextAttribute(hConsole, 240); 
}