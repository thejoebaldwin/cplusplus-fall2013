#include "Superhero.h"

Superhero::Superhero()
{
	first_name_ = "";
	last_name_ = "";
	power_ = "";
	name_ = "";
}

Superhero::Superhero(string first_name, string last_name
					 ,string power, string name)
{
	first_name_ = first_name;
	last_name_ = last_name;
	power_ = power;
	name_ = name;
}

string Superhero::first_name()
{
	return first_name_;
}

string Superhero::last_name()
{
	return last_name_;
}


string Superhero::power()
{
	return power_;
}

string Superhero::name()
{
	return name_;
}

void Superhero::set_first_name(string first_name)
{
	first_name_ = first_name;
}

void Superhero::set_last_name(string last_name)
{
	last_name_ = last_name;
}

void Superhero::set_power(string power)
{
	power_ = power;
}

void Superhero::set_name(string name)
{
	name_ = name;
}
