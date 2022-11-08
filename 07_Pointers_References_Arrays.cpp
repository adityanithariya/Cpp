#include <iostream>
using namespace std;

int main()
{
    /*
	Derived Data Types:
	   1. Pointers
	   2. References
	   3. Arrays
	*/

    cout << "Pointers(Address keepers):\nIt is a type of data type which stores address of another data type.\n";
	int w = 5;
	// data type --> Pointer
	// & --> Address of operator
	int *v = &w; //Here * is used for making a integer type pointer
	cout << "The address of w is " << &w << endl;
	cout << "The value of v is " << v << endl;

	// * --> Dereferencing Operator
	cout << "The value of v is " << v << endl;
	cout << "The value of *v = w is " << *v << "\n\n";

	cout << "Pointer to Pointer:\n";
	// Pointer --> Pointer
	int **u = &v;

	// Address Check
	cout << "The address of v is " << &v << endl;
	cout << "The value of u is " << u << endl;

	// Dereferencing
	cout << "The value of u is " << u << endl;
	cout << "The value of *u = v is " << *u << endl;
	cout << "The value of **u = w is " << **u << "\n\n";

    cout << "Reference Variables: \n";
    float p = 25;
    float &q = p;
    cout << "Value of p is: " << p << ", q(Reference of p) is: " << q << "\n\n";

    cout << "Arrays: Allocation of Contiguous(next to each other) Memory Location.\nIt is similar to list in python but have smooth memory access\n";
	int marks[] = {10,
					20,
					30};
	marks[3] = 40;

	i = 0;
	while (i < 4)
	{
		cout << marks[i] << endl;
		i++;
		if (i == 4)
		{
			cout << "\n";
		}
	}

	cout << "Pointers in Arrays:\nWhen we point address of array it is pointed at 0th element of array.\nArray Items are\n";
	int *t = marks; // Here we don't use & for addressing
	i = 0;
	// Arithmetic in pointers
	while (i < 4)
	{
		cout << *(t + i) << endl;
		i++;
	}
    return 0;
}