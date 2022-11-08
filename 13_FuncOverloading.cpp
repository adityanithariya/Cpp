#include <iostream>
using namespace std;

// Function Overloading
// Sum Function
int sum(int a, int b)
{
	int c;
	c = a + b;
	return c;
}

int sum(int a, int b, int c)
{
	return a + b + c;
}

// Volume Function
int volume(int a)
{
	return (a*a*a);
}

int volume(int a, int b, int c)
{
	return (a*b*c);
}

int volume(double r, int h)
{
	return (3.14 * r * r * h);
}

int main()
{
    cout << "Function Overloading:\n";
	/* If we want to make functions with same name but different types/numbers of args compiler automatically 
	detects for every call by given types/number of args. If func call args doesn't match any defined function
	args' types or number, then only function throws error.
	*/
	cout << "First Sum Function with two args as input:\n";
	cout << "The sum of 7, 8 is " << sum(7, 8) << "\n";
	cout << "Second Sum Function with three args as input:\n";
	cout << "The sum of 7, 8, 9 is " << sum(7, 8, 9) << "\n";

	cout << "Volume Function Overloaded:\n";
	cout << "Volume of cube of side 3 is: " << volume(3) << endl;
	cout << "Volume of cuboid of 3, 4, 5 is: " << volume(3, 4, 5) << endl;
	cout << "Volume of cylinder of radius 3, height 5 is: " << volume(3, 5) << "\n";
    
    return 0;
}