#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

int main()
{
    double quantity = 0;
	double price = 0;
	double total = 0;
	
	//cout << fixed << setprecision(2);
	cout << "Please enter the number of books:";
	cin >> quantity;
	cout << endl << "Please enter the price per book:";
	cin >> price;
	total = quantity * price;
	cout << "The Total is:" << total << endl;
	cout << "Press any key to quit";


	_getch();


	return 1;
}