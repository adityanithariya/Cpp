#include <iostream>
using namespace std;

// Single Line Comment
/*
Multi Line Comment
*/

int var = 10; //This is a global variable

int main()
{
	cout << "Built-in/Primitive Data Types:\n";
	int x = 10;
	int x1 = 5;
	float y = 3.14;
	char z = 'c';
	double c = 100;
	bool e = true;
	// void also.

	cout << "Size Occupiesd by Data Types(In bits):\n";
	cout << "x = " << sizeof(x) << endl;
	cout << "y = " << sizeof(y) << endl;
	cout << "z = " << sizeof(z) << endl;
	cout << "e = " << sizeof(e) << endl;
	cout << "c = " << sizeof(c) << "\n\n";

	cout << "Variable Scope:\n";
	int var = 20;
	cout << "Global var = " << ::var << "\nLocal var = " << var << "\n\n";

	return 0;
}