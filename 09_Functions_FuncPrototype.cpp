#include <iostream>
using namespace std;

// Function Prototype
// 1. void:
void greet(); // Acceptable
// void greet(void); // Acceptable

// 2. int:
// Acceptable
int sum(int a, int b);
// int sum(int, int)

// Non Acceptable
// int sum(int a, b)

int main()
{
    cout << "Functions and Function Prototype\n";
    /* Types of functions:
		1. void func(): without any return value
		2. int func(): it can return any value
	*/

    greet();

    int num1, num2;

    cout << "Enter value of num1 and num2\n";
    cin >> num1 >> num2;
    cout << "The sum of num1 and num2 is " << sum(num1, num2) << "\n\n"; // num1, num2 are actual parameters.

    return 0;
}

void greet()
{
    cout << "Hello, Good Morning!\n";
}

int sum(int a, int b)
{
    // a and b are formal parameters.
    int c;
    c = a + b;
    return c;
}
