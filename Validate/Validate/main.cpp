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
	int total = 0;
	int exp = 0;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		char c = s[i];
	
		int value = 0;
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
        
		
		total +=  (value * pow(10, exp));
		exp++;
	}
	return total;
}


bool isNumeric(string s)
{
	int total = 0;
	bool success = false;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		char c = s[i];
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
			success = false;
			break;
		}
	}
	return success;
}

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