#include <iostream>
using namespace std;

#ifndef _COLLECTION_DEF
#define _COLLECTION_DEF


template <class T>
class Collection
{
private:
	T* array_;
	int length_;

public:
	Collection();
	Collection(int);
	int length();
	T& operator[](int);
	//friend ostream& operator<<(ostream&, Collection<T>&);
    void add(T);
};

template <class T>
Collection<T>::Collection()
{
	Collection(1);
}

template <class T>
Collection<T>::Collection(int length)
{
	length_ = length;
	array_ = new T[length_];
}

template <class T>
int Collection<T>::length()
{
	return length_;
}

template <class T>
T& Collection<T>::operator[] (int index)
{
	return array_[index];
}

template <class T>
ostream& operator<<(ostream &out,  Collection<T> &c)
{
 out << "Length:" << c.length() << endl;
 for (int i = 0; i < c.length(); i++)
 {
	out << i <<   ":" << c[i] << endl;
 }
 return out;
}

template <class T>
void Collection<T>::add(T value)
{
	//declare new array length + 1
	T* new_array = new T[length_ + 1];
	//copy old array values to new array
	for (int i = 0; i < length_; i++)
	{
		new_array[i] = array_[i];
	}
	length_++;
	new_array[length_ - 1] = value;
	//**free up old array_ memory**
	delete[] array_;
	//set array_ pointer to new array
	array_ = new_array;
}

#endif