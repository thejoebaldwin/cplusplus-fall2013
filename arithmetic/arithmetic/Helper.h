#include <iostream>
#include <conio.h>
//need for shell color on windows machine
#include <Windows.h>

using namespace std;


class Helper
{
	private:
		//nothing here
	public:
		Helper();
		bool IsNumeric(string);
		bool IsNumericInt(string);
		int ConvertToInt(string);
		double ConvertToDouble(string);
		void SetConsole();

};


