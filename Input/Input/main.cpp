#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	float test_num;
	bool quit = false;
	char test_input;

	while (!quit) 
	{
		cout << "Please enter a number: ";
		cin >> test_num;
		cout << "You entered " << setprecision(4) << test_num << endl;
		cout << "Press any key to continue, 'q' to quit:";
		//cin >> test_input;
		test_input = _getch();

		quit = (test_input == 'q');
		/*
		if (test_input == 'q')
		{
			quit = true;
		}
		*/
	}

	//_getch();
	return 0;
}