#include <iostream>
#include <conio.h>
#include <iomanip>
//need for shell color on windows machine
#include <Windows.h>
#include <string>
using namespace std;

//need to declare (but not define) before use
void setConsole();
void heroPrint(string, string);
void heroPrint(string, string, float);
string formatMoney(float);

const int COLUMN_ONE_WIDTH = 40;
const int COLUMN_TWO_WIDTH = 20;

int main()
{
	setConsole();
	
	//int column_one_width = 40;
	//int column_two_width = 20;
	int total_width = COLUMN_ONE_WIDTH + COLUMN_ONE_WIDTH;

	cout << "**Superheroes**" << endl;
	cout << setfill('-');
	cout << setw(total_width) << "" << endl;
	cout << setfill(' ');
	cout << left << setw(COLUMN_ONE_WIDTH) << "NAME" << setw(COLUMN_TWO_WIDTH) << "POWER" << endl;
	
	heroPrint("Iron Man", "Fancy Suit", 1000000000.0f);
	heroPrint("Hulk", "Smash", 0.005f);


	_getch();
	return 0;
}

string formatMoney(float money)
{
    //create a temporary character array
	char temp_price[16];
	//use sprintf to format the string two decimal places
	sprintf_s(temp_price, "$%.2f", money);
	return temp_price;
}

void heroPrint(string name, string power)
{
	cout << setw(COLUMN_ONE_WIDTH) << name
		<< setw(COLUMN_TWO_WIDTH) << power << endl;
}

void heroPrint(string name, string power, float money)
{
	cout << left << setw(COLUMN_ONE_WIDTH) << name
		 << left << setw(COLUMN_TWO_WIDTH) << power
		 << right << setw(COLUMN_TWO_WIDTH) << formatMoney(money)
		 << endl;
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