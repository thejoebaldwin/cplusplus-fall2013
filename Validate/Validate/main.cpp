#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
//need for shell color on windows machine
#include <Windows.h>
#include <math.h>
using namespace std;

//need to declare (but not define) before use
void setConsole();
//first example in class
void validate();
bool isNumeric(string);
int convertToInt(string);

int main()
{
	setConsole();
  	string user_value;

	cout << "Please enter a value:";
	cin >> user_value;
	
	//call isNumeric before calling convertToInt
	if (isNumeric(user_value))
	{
		cout << "success";
		int user_number = convertToInt(user_value);
		cout << "You entered " << user_number << endl;
	}
	else
	{
		cout << "fail";
	}


	_getch();
	return 0;
}

int convertToInt(string s)
{
	//holds running total
	int total = 0;
	//start at 10 ^ 0
	//	track exponent separate from index i
	int exp = 0;
	//loop through word, start at end
	for (int i = s.length() - 1; i >= 0; i--)
	{
		char c = s[i];
		//temporary value for 1s, 10s, 100s, etc.
		int value = 0;
		//translate character to integer value
		if (c == '0')
		{
			value = 0;
		}
		else if (c == '1')
		{
			value = 1;
		}
		else if (c == '2')
		{
			value = 2;
		}
		else if (c == '3')
		{
			value = 3;
		}
		else if (c == '4')
		{
			value = 4;
		}
		else if (c == '5')
		{
			value = 5;
		}
		else if (c == '6')
		{
			value = 6;
		}
		else if (c == '7')
		{
			value = 7;
		}
		else if (c == '8')
		{
			value = 8;
		}
		else if (c == '9')
		{
			value = 9;
		}
		//add the current value times it's place (1s, 10s, 100s, etc) to the
		//	running total
		//	use pow(10 ^ 0) instead of (10 ^ 1)
		//	pow(10 ^ 0) = 1 DOES NOT EQUAL (10 ^ 0) = 10
		total +=  (value * pow(10, exp));
		//increment exponent for following iteration
		exp++;
	}
	return total;
}


//returns true if string is numeric value
bool isNumeric(string s)
{
	bool success = false;
	//start at end of string (1's place).
	for (int i = s.length() - 1; i >= 0; i--)
	{
		//get the digit
		char c = s[i];
		//look for characters 0-9
		if (c == '0')
		{
			success = true;
		}
		else if (c == '1')
		{
			success = true;
		}
		else if (c == '2')
		{
			success = true;
		}
		else if (c == '3')
		{
			success = true;
		}
		else if (c == '4')
		{
			success = true;
		}
		else if (c == '5')
		{
			success = true;
		}
		else if (c == '6')
		{
			success = true;
		}
		else if (c == '7')
		{
			success = true;
		}
		else if (c == '8')
		{
			success = true;
		}
		else if (c == '9')
		{
			success = true;
		}
		else
		{
			//if 0-9 not found then set success to false and break from for loop
			success = false;
			break;
		}
	}
	return success;
}



//code used to demo cin.fail(), cin.clear(), cin.ignore()
void validate()
{
	int test1, test2;


	while (true)
	{
		cout << "Please enter a number:";
		cin >> test1;
	
		if (cin.fail())
		{
			cout << "Bad Input, Try Again:" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else
		{
			cout << endl << "You entered " << test1 << endl;
		}
	}


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