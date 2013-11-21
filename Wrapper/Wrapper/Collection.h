#include <iostream>
using namespace std;

class Collection
{
private:
	int* array_;
	int length_;

public:
	Collection();
	Collection(int);
	int length();
	int& operator[](int);
	friend ostream& operator<<(ostream&, Collection&);
    void add(int);
};

Collection::Collection()
{
	Collection(1);
}

Collection::Collection(int length)
{
	length_ = length;
	array_ = new int[length_];
}

int Collection::length()
{
	return length_;
}

int& Collection::operator[] (int index)
{
	return array_[index];
}


ostream& operator<<(ostream &out, Collection &c)
{
 out << "Length:" << c.length() << endl;
 for (int i = 0; i < c.length(); i++)
 {
	out << i <<   ":" << c[i] << endl;
 }
 return out;
}

void Collection::add(int num)
{
	//declare new array length + 1
	int* new_array = new int[length_ + 1];
	//copy old array values to new array
	for (int i = 0; i < length_; i++)
	{
		new_array[i] = array_[i];
	}
	length_++;
	new_array[length_ - 1] = num;
	//**free up old array_ memory**
	delete[] array_;
	//set array_ pointer to new array
	array_ = new_array;
}