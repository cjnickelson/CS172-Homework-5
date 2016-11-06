// Carter Nickelson Homework 5

#pragma once
#include<iostream>

template<typename T>
class vector
{
	T* elements;
	int num;
	int capacity;
	
public:
	// default constructor sets capacity to 16 and num to 0.
	vector<T>()
	{
		num = 0;
		capacity = 16;
		elements = new T[capacity];
	}
	// this constructor allows the user to determine the size of the vector
	vector<T>(int size)
	{
		num = size;
		capacity = size;
		elements = new T[capacity];
		for (int i = 0; i < size; i++)
		{
			elements[i] = 15;
		}
	}
	// this constructor allows the user to set the size of the vector, and initial values to put into this vector
	vector<T>(int size, T defaultValue)
	{
		num = size;
		capacity = size;
		elements = new T[capacity];
		// sets each value to the default
		for (int i = 0; i < size; i++)
		{
			elements[i] = defaultValue;
		}
	}
	// allows the user to expand the vector to a specified value
	void setCapacity(int cap)
	{
		// wont let the user decrease the size of an array such that there is less space than values in the array
		if (cap < num)
			return;
		else 
		{
			// if there will be enough space, create a temporary holding array
			T* old = elements;
			// change the capacity to the specified value
			capacity = cap;
			// allocate a new space for elements, with the new capacity
			elements = new T[capacity];
			// copy the old elements into the new one
			for (int i = 0; i < num; i++)
				elements[i] = old[i];
			// for the remaining unused space in the array, set all the values to 0
			for (int i = num; i < capacity; i++)
				elements[i] = 0;
			// delete the temporary holding array
			delete[] old;
		}
	}
	// basic setter for the size of a vector
	void setNum(int size)
	{
		num = size;
	}
	int getCapacity()
	{
		return capacity;
	}
	// append a value to the end of the vector
	void push_back(T value)
	{
		// if there is no space in the array...
		if (num >= capacity)
		{
			// make space, using the old double capacity function
			T* old = elements;
			capacity = 2 * num;
			elements = new T[capacity];
			for (int i = 0; i < num; i++)
				elements[i] = old[i];
			
			delete[] old;
		}
		// then, put the new value into the first open spot
		elements[num] = value;
		// increment the number of values in the array
		num++;
	}
	// remove the  last value from the array
	void pop_back()
	{
		num--;
	}
	// basic getter for the size
	unsigned const int size()
	{
		return num;
	}
	// rewrite the value at a certain index of the array to a specified value
	void setValueAt(int index, T value)
	{
		elements[index] = value;
	}
	// basic getter for whatever may be in the vector
	T at(int index)
	{
		return elements[index];
	}
	// checks to see if the vector is empty by checking if size=0
	const bool empty()
	{
		return (num == 0 ? true : false);
	}
	// removes all values from the vector
	void clear()
	{
		// writes over all values to be 0
		for (int i = 0; i < num; i++)
			elements[i] = 0;
		num = 0;
	}

	// This function refuses to work for me, but here's how it is supposed to work (maybe you can figure out why it doesnt):
	void swap(vector v2)
	{
		// if one vector is larger than the other, increase the capacity of the smallest one to accomodate for the new values it will receive
		if (v2.size() > num)
			this->setCapacity(v2.size());
		else 
			v2.setCapacity(num);

		// create a temporary holding array
		T* temp = elements;
		// allocate new space for the elements of v1 (the vector which this function is called upon)
		elements = new T[v2.size()];
		
		// copy the elements of v2 into the new space for v1
		for (int i = 0; i < v2.size(); i++)
			elements[i] = v2.at(i);

		// store the size of v1 for future
		int tempNum = v2.size();

		// copy the contents of temp into v2 using the setValueAt function described above
		for (int i = 0; i < num; i++)
			v2.setValueAt(i, temp[i]);
	
		// get rid of the temporary holding space
		delete[] temp;
		// set the size of v2 to what v1's size used to be
		v2.setNum(num);
		// set the size of v1 to what v2's size used to be
		num = tempNum;
	}
};
