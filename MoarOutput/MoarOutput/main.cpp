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
	setConsole();

	int red = 0;
	int green = 204;
	int blue = 0;
	
	cout << "Red: " << oct << red << endl;
	cout << "Green: " << oct << green << endl;
	cout << "Blue: " << oct << blue << endl;
  	
	cout << "Red: " << dec << red << endl;
	cout << "Green: " <<  green << endl;
	cout << "Blue: " <<  blue << endl;
  	



	cout << "Size Of Float:" << sizeof(int) << endl;
	cout << "Size Of Float:" << sizeof(float) << endl;
	cout << "Size Of Double:" << sizeof(double) << endl;


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