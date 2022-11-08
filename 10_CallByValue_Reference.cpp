#include <iostream>
using namespace std;

// Call by Value Function
int SwapByValue(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
	return a, b;
}

// Call by Reference Functions
// 1. Using Pointer:
int SwapByPointer(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	return *a, *b;
}

// 2. Using Reference Variables:
int SwapByReference(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
	return a, b;
}

int main()
{
	cout << "Call by Value, and by reference\n";
	/* When we call a function like func(*args) we call it by value, means we make a copy of them in new memory with 
	new name then proceed operations or whatever we want to do then function return same value at end if we return 
	both a and b. To override this copying we use referencing.
	*/

	int j, k;
	cout << "Enter the value of j and k:\n";
	cin >> j >> k;
	int a = j;
	int b = k;
	cout << "Value Swaper\nWe will make a function which will swap value of two variables.\n\n";

	cout << "Call by Value(This will not swap value):" << endl;
	SwapByValue(j, k);
	cout << "The value of j is " << j << endl;
	cout << "The value of k is " << k << "\n\n";

	cout << "Call by Reference:\n\n";
	cout << "Swap by Pointer:\n";
	SwapByPointer(&j, &k);
	cout << "The value of j is " << j << endl;
	cout << "The value of k is " << k << "\n\n";

	j = a;
	k = b;
	cout << "Swap by Reference Variable:\n";
	SwapByReference(j, k);
	cout << "The value of j is " << j << endl;
	cout << "The value of y is " << k << "\n\n";

	return 0;
}