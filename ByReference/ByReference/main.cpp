#include <iostream>
#include <conio.h>

using namespace std;


int ice_cream(int, int &, int &, int &);

int ice_cream(int menu, int &vanilla, int &chocolate, int &strawberry)
{
	switch (menu)
	{
	case 1:
		vanilla--;
		break;

	case 2:
		chocolate--;
		break;
	case 3:
		strawberry--;
		break;
	}
	if (vanilla < 1 || chocolate < 1 || strawberry < 1)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

int main()
{
	int vanilla_quantity = 3;
	int chocolate_quantity = 3;
	int strawberry_quantity = 3;


	while (true)
	{
		int menu_choice = -1;
		cout << "Please select a flavor:" << endl;
		cout << "1. Vanilla"<< endl << "2. Chocolate" << endl << "3. Strawberry" << endl;
		cin >> menu_choice;
		int result = ice_cream(menu_choice, vanilla_quantity, chocolate_quantity, strawberry_quantity);
		if (result < 0)
		{
				cout << "Sorry we are out of that flavor" << endl;
		}
		else
		{
			cout << "Thank you" << endl;
		}

	}

}
