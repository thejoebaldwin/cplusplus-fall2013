#include <iostream>
#include <conio.h>
#include "Helper.h"
#include "Superhero.h"
#include <string>

using namespace std;


int main()
{
	Helper h = Helper();
	h.SetConsole();


	

	Superhero heroes[3];

	heroes[0] =  Superhero("Bruce", "Banner", "Hulk Smash", "Hulk") ;
	heroes[1] = Superhero("Eric", "Masterson", "Mjolnir", "Thor");
	heroes[2] =  Superhero("Henry", "Pymn", "Grow/Shrink", "Ant Man");
	
	for (int i = 0; i < 3; i++)
	{
		cout << heroes[i].first_name() << " " << heroes[i].last_name() 
			<< ": " << heroes[i].name() << endl;
	}

	cout << "Please enter a first name to search:";
	string first_name = "";
	//cin >> first_name;
	getline(cin, first_name);
	

	


	bool found = false;
	int count = 0;

	//loop through all superheroes
	while (found == false && count < 3)
	{
		//look for first_name = superhero.firstname
		if (first_name == heroes[count].first_name()
			|| first_name == heroes[count].last_name()
			|| first_name == heroes[count].name())
		{
			cout << "Found \"" << first_name << "\" on: " 
				<< heroes[count].name() << "=" << heroes[count].first_name()
				<< " " << heroes[count].last_name() << endl;
			found = true;
		}
		count++;
	}
	if (!found)
	{
		cout << "Sorry, there is no superhero by that name of " << first_name << endl;
	}



	_getch();
	return 0;
}