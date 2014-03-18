#include <iostream>
#include <conio.h>
//need for shell color on windows machine
#include <Windows.h>
#include "Collection.h"

using namespace std;


class Helper
{
	private:
		//nothing here
	public:
		Helper();
		static bool IsNumeric(string);
		static bool IsNumericInt(string);
		static int ConvertToInt(string);
		static double ConvertToDouble(string);
		static void SetConsole();
		static Collection<string> Split(string, char); 
};


