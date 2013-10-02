#include "Helper.h"

Helper::Helper()
{
	//nothing to do here
}

double Helper::ConvertToDouble(string s)
{
  //holds running total
	double total = 0;
	bool decimal_point_found = false;
	int exp = s.length() - 1;

	//test if contains decimal point first
	for (int i = 0; i  < s.length(); i++)
	{
		char c = s[i];
		if (c == '.')
		{
			decimal_point_found = true;
		}
		//if contains a decimal point, then account for string length
		if (decimal_point_found)
		{
			exp--;
		}
	}
	//loop through word
	for (int i = 0; i  < s.length(); i++)
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
		//if contains a decimal point, then start 0.1, 0.01, etc.
		if (c == '.')
		{
			exp = -1;
		}
		else
		{
			//add the current value times it's place (1s, 10s, 100s, etc) to the
			//	running total
			//	use pow(10 ^ 0) instead of (10 ^ 1)
			//	pow(10 ^ 0) = 1 DOES NOT EQUAL (10 ^ 0) = 10
			double temp =  (value * pow(10, exp));
			total +=  temp;
			//increment exponent for following iteration
			exp--;
		}
		
	}
	return total;

}

int Helper::ConvertToInt(string s)
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

bool Helper::IsNumericInt(string s)
{
	bool success = true;
	//start at end of string (1's place).
	for (int i = s.length() - 1; i >= 0; i--)
	{
		//get the digit
		char c = s[i];
		//look for characters 0-9
		if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4'
			|| c == '5' || c == '6' || c == '7' || c == '8' || c == '9')
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

//returns true if string is numeric value
bool Helper::IsNumeric(string s)
{
	bool success = true;
	bool decimal_point_found = false;
	//start at end of string (1's place).
	for (int i = s.length() - 1; i >= 0; i--)
	{
		//get the digit
		char c = s[i];
		//look for characters 0-9
		if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4'
			|| c == '5' || c == '6' || c == '7' || c == '8' || c == '9')
		{
			success = true;
		}
		else if (c == '.')
		{
			if (!decimal_point_found)
			{
				decimal_point_found = true;
			}
			else
			{
				//if decimal point found already, then not a valid number
				success = false;
			}
			//if decimal is at end of string not valid number
			if (i == s.length() - 1)
			{
				success = false;
			}
		}
		else
		{
			//if 0-9 not found then set success to false and break from for loop
			success = false;
		}
		if (!success)
		{
			break;
		}
	}
	return success;
}




void Helper::SetConsole()
{
	 //color value for console
	int color = 25;  
	//console reference	
	HANDLE	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	PCONSOLE_FONT_INFOEX font = new CONSOLE_FONT_INFOEX();
   	font->cbSize = sizeof(CONSOLE_FONT_INFOEX);
   
    //CONSOLE_FONT_INFOEX is defined in windows header
	GetCurrentConsoleFontEx(hConsole, false, font);
	
	//PCONSOLE_FONT_INFOEX is the same as CONSOLE_FONT_INFOEX*
    font->dwFontSize.X = 10;
    font->dwFontSize.Y = 18;
	SetCurrentConsoleFontEx(hConsole, false, font);
	SetConsoleTextAttribute(hConsole, 240); 
}