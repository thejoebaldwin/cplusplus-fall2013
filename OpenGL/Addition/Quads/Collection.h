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
	void sort();
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
Collection<T> operator+(Collection<T> &num1, Collection<T> &num2)
{
	Collection<T> num3(0);

	for (int i = 0; i < num1.length(); i++)
	{
		num3.add(num1[i]);
	}

	for (int i = 0; i < num2.length(); i++)
	{
		num3.add(num2[i]);
	}
	return num3;
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


template <class T>
void Collection<T>::sort()
{
		//sort me!
	bool is_sorted = true;
	//loop until array is sorted
	do
	{
		is_sorted = true;
		//check every element to see if sorted
		for (int i = 0; i < length_ - 1; i++)
		{
			if (array_[i] > array_[i + 1])
			{
				T temp = array_[i];
				array_[i] = array_[i + 1];
				array_[i + 1] = temp;
				is_sorted = false;
			}
		}
	} while (!is_sorted);
	
}

#endif