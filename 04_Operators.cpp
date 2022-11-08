#include <iostream>
using namespace std;

int main()
{
	cout << "Arithmetic Operators:\n";
	cout << "The value of a + b is: " << (a + b) << endl;
	cout << "The value of a - b is: " << (a - b) << endl;
	cout << "The value of a * b is: " << (a * b) << endl;
	cout << "The value of a / b is: " << (a / b) << endl;
	// cout << "The value of a % b is: " << ((int)a % (int)b) << endl; // This is ignored due to
	// strange answer of a/b when b = 0.
	cout << "The value of a++ is: " << (a++) << endl;
	cout << "The value of a-- is: " << (a--) << endl;
	cout << "The value of ++a is: " << (++a) << endl;
	cout << "The value of --a is: " << (--a) << "\n\n";

	cout << "Comparison operators:" << endl;
	cout << "The value of a == b is " << (a == b) << endl;
	cout << "The value of a != b is " << (a != b) << endl;
	cout << "The value of a >= b is " << (a >= b) << endl;
	cout << "The value of a <= b is " << (a <= b) << endl;
	cout << "The value of a > b is " << (a > b) << endl;
	cout << "The value of a < b is " << (a < b) << "\n\n";

	cout << "Logical Operators:\n";
	cout << "And Operator ((a==b) && (a<b)) is:" << ((a == b) && (a < b)) << endl;
	cout << "Or Operator ((a==b) || (a<b)) is:" << ((a == b) || (a < b)) << endl;
	cout << "Not Operator (!(a==b)) is:" << (!(a == b)) << "\n\n";

	return 0;
}