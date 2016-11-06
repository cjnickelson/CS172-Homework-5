#include<iostream>
#include<string>
#include<iomanip>
#include"Vector(exercise 3).h"
#include<ctime>
#include"Account (exercise 5).h"

using namespace std;

template<typename T>
int linearSearch(T list[], T key, int size);

template<typename T>
bool isSorted(T list[], int size);

template<typename T>
void shuffle(vector<T>& v);

int main()
{
	// create three arrays, one of ints (sorted) one of doubles, and one of strings (both not sorted)
	int arrayOfInts[8] = { 1,2,3,4,5,6,7,8};
	double arrayOfDoubles[8] = { 3.01,3,2.99,15,6,-2,0,-1.3 };
	string arrayOfStrings[8] = { "Hi","How are you?","I'm well","And you?","I'm hungry","Pizza","We come in peace","Enough talk. Let's fight" };
	// create ints to hold the return values of the linear checks
	int checkInts = linearSearch(arrayOfInts,-12, 8);
	int checkDoubles = linearSearch(arrayOfDoubles, 25.1, 8);
	string check = "Pizza";
	int checkStrings = linearSearch(arrayOfStrings, check, 8);
	// if any  of these return -1, display that the array did not contain the specified value
	if (checkInts == -1)
		cout << "The number -12 does not occur in the first array." << endl;
	// otherwise, display the index where it does occur (the return value of the linearcheck function)
	else cout << "the number -12 occurs at index " << checkInts << "." << endl;
	if (checkDoubles == -1)
		cout << "The number 25.1 does not occur in the second arary" << endl;
	// display the index
	else cout << "The number 25.1 occurs at index " << checkDoubles << "." << endl;
	if (checkStrings == -1)
		cout << "The word \"Pizza\" does not occur in the third array" << endl;
	// display the index
	else cout << "The word \"Pizza\" occurs at index " << checkStrings << "." << endl;
	// create bools to check if each array is sorted
	// check with the isSorted template function
	bool sortInts = isSorted(arrayOfInts, 8), sortDoubles = isSorted(arrayOfDoubles, 8), sortStrings = isSorted(arrayOfStrings,8);
	// display the sorted status of each array
	cout << "The array of ints is " << (sortInts == true ? "" : "not ") << "sorted." << endl;
	cout << "The array of doubles is " << (sortDoubles == true ? "" : "not ") << "sorted." << endl;
	cout << "The array of strings is " << (sortStrings == true ? "" : "not ") << "sorted." << endl;
	// create two arrays of 10 values
	vector<int> first(10);
	vector<int> second(10);
	// rewrite the first array to have values 1,2,3,4, all the way up to 10
	for (int i = 0; i < first.size(); i++)
		first.setValueAt(i,i+1);
	// append the number 11 to first
	first.push_back(11);
	// display the first array
	for (int i = 0; i < first.size(); i++)
		cout << first.at(i) << endl;
	cout << endl;
	// use the shuffle function to shuffle and display the new shuffled array
	shuffle(first);
	cout << endl;
	// swap the two arrays
	first.swap(second);

	// display the swapped arrays
	for (int i = 0; i < first.size(); i++)
		cout << first.at(i) << endl;
	cout << endl;
	for (int i = 0; i < second.size(); i++)
		cout << second.at(i) << endl;

	// create an account of name George, id 1122 and balance 1000
	string name = "George";
	Account account(name, 1122, 1000);
	// make various deposits
	account.deposit(30);
	account.deposit(40);
	account.deposit(50);
	account.withdraw(5);
	account.withdraw(4);
	account.withdraw(2);
	// this is what will not work for me. I cannot figure out how to acess members of a vector if those vales are themselves classes rather than ints, doubles, strings, etc
	/*for (int i = 0; i < account.transactions.size(); i++)
	{
		Transaction t = (account.transactions).at(i);
		account.displayTransactions(t);
	}
	*/
	return 0;
}

// templated function for a linear search.
template<typename T>
int linearSearch( T list[], T key, int size)
{
	// goes through each index until it finds a match. If it finds one, it will return that index
	for (int i = 0; i < size; i++)
	{
		if (key == list[i])
			return i;
	}
	// if it deos not, it will return -1
	return -1;
}

// templated function for determining if an array is sorted
template<typename T>
bool isSorted(T list[], int size)
{
	// goes through each index, and if that value is smaller than the one before it, it must not be sorted, so it returns false
	for (int i = 1; i < size; i++)
	{
		if (list[i - 1] > list[i])
			return false;
	}
	// if it makes it all the way through, it must be sorted
	return true;
}

// vector shuffling function
template<typename T>
void shuffle(vector<T>& v)
{
	// allocates space for a temporary holding array of the same size as the vector
	T* temp = new T[v.size()];
	// copies the values from the vector into the holding array
	for (int i = 0; i < v.size(); i++)
		temp[i] = v.at(i);
	// initializes ints for the size of the array, variable x, and sets i=0
	int size = v.size(),x,i=0;
	// sets the seed
	srand(time(NULL));
	// loop continues while the size variable (originally equal to the size of the array) is posititve
	while (size > 0)
	{
		// randomize x between 0 and the size of the array as the array shrinks
		x = rand() % size;
		// set the value at the next index to the value found at the random location x
		v.setValueAt(i, temp[x]);
		// increment i to advance along the vector
		i++;
		// move every value in the temporary array down one, to remove the "hole" and match with size
		for (int j = x; j < size; j++)
			temp[j] = temp[j + 1];
		// decrement size to force x to be a value which is found in the array
		size--;
	}
	// display the new shuffled array
	for (int j = 0; j < v.size(); j++)
		cout << v.at(j) << endl;
	// delete the temporary
	delete[] temp;
}