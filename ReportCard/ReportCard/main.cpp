#include <iostream>
#include <conio.h>
#include <iomanip>
//need for shell color on windows machine
#include <Windows.h>
using namespace std;

//need to declare (but not define) before use
void setConsole();

int main()
{
	float score1 = 0.95f;
	float score2 = 1.0f;
	float score3 = 0.05f;

	float average = (score1 + score2 + score3) / 3.0;

	int column_one_width = 40;
	int column_two_width = 10;

	setConsole();

	cout << fixed << setprecision(2);

  	cout << "Report Card" << endl;
	cout << setfill('-');
	cout << left << setw(column_one_width + column_two_width) << "-" << endl;
	cout << setfill(' ');
	cout << left << setw(column_one_width) << "Assignment" << left << setw(10) << "Score" << endl;
	
	cout << setfill('.');

	cout << left << setw(column_one_width) << "#1: Hello World";
	cout << right << setw(column_two_width) << score1 * 100 << "%" << endl;
	
	cout << left << setw(column_one_width) << "#2: Miles Calculator";
	cout << right << setw(column_two_width) << score2 * 100 << "%" << endl;
	
	cout << left << setw(column_one_width) << "#3: String Formatting";
	cout << right << setw(column_two_width) << score3 * 100 << "%" << endl;

	cout << setfill('-');
	cout << left << setw(column_one_width + column_two_width) << "-" << endl;

	cout << setfill(' ');
	cout << right << setw(column_one_width + column_two_width) << average * 100 << "%" << endl;

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