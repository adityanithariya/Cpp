// Header files
#include <iostream>	 //Input/Output Stream
#include <iomanip>	 // For setw manipulator

// This is not a good practice as it will create problems in debugging.
using namespace std; //Making std as global

// Single Line Comment
/*
Multi Line Comment
*/

int var = 10; //This is a global variable

typedef struct person{
	string name;
	int age;
	float salary;
	bool gender;
} prsn;

union money
{
	int RiceBags;
	char CarName;
	float Pounds;
	bool Lend;
};

enum Gender
{
	male,
	female
};

// Function Prototype
// 1. void:
void greet(); // Acceptable
// void greet(void); // Acceptable

// 2. int:
// Acceptable:
int sum(int a, int b);
// int sum(int, int)

// Not Acceptable:
// int sum(int a, b)

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

// Inline Functions
inline float product(float x, float y)
{
	int z = x * y;
	return z;
}

int moneyInterested(int moneyRecieved, float factor = 1.08)
{
	return (moneyRecieved * factor);
}

// const char a // When we will do something with 'a' then there is a chance that 'a' will change.
// To prevent that we use constant.

// static char a // We use this in any function when we want that value of this function doesn't initialises when we call function second time

// Recursive Function
// Factorial of a Number
int factorial(int n)
{
	if (n == 1)
	{
		return 1;
	}
	return n * factorial(n-1);
}

// Nth term of Fibonacci Series
int fib(int n)
{
	if (n < 2)
	{
		return 1;
	}
	return fib(n - 2) + fib(n - 1);
}

// Function Overloading
// Sum Function with three args
int sum(int a, int b, int c)
{
	return a + b + c;
}

// volume Function Overloading
int volume(int a)
{
	return (a * a * a);
}

int volume(int a, int b, int c)
{
	return (a * b * c);
}

int volume(double r, int h)
{
	return (3.14 * r * r * h);
}

main() //Main Function of Program where execution starts
{
	cout << "# C++ Tutorial:\n\n";

	cout << "Built-in/Primitive Data Types:\n";
	int x = 10;
	int x1 = 5;
	float y = 3.14;
	char z = 'c';
	double c = 100.328;
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

	cout << "Reference Variables: \n";
	float p = 25;
	float &q = p;
	cout << "Value of p is: " << p << ", q(Reference of p) is: " << q << "\n\n";

	cout << "TypeCasting: \n";
	cout << "x + x1 in int is: " << (x + x1) << endl;
	cout << "x + x1 in str is: " << (to_string(x) + to_string(x1)) << "\n\n";

	cout << "Constant Data Types: \n";
	const int xy = 15;
	cout << "xy = 20;\nThis will give error as xy is a const variable\n\n";

	cout << "Manipulators: \n";
	cout << "endl: It is used for newline.\nsetw: It is from iomanip which specifies width of output.\n\n";
	cout << "Output will be in four digit space:" << setw(4) << c << "\n\n";

	cout << "Basic Input/Output(by iostream:std)\n";
	float a, b;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "\n";

	cout << "Arithmetic Operators:\n";
	cout << "The value of a + b is: " << (a + b) << endl;
	cout << "The value of a - b is: " << (a - b) << endl;
	cout << "The value of a * b is: " << (a * b) << endl;
	cout << "The value of a / b is: " << (a / b) << endl;
	// cout << "The value of a % b is: " << ((int)a % (int)b) << endl; // This is ignored due to strange answer of a/b when b=0
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

    /* Control Structures in C++:
		1. Sequence Structures:
			All code simply written in any function is example of Sequence Structures.
		2. Selection Structures:
			When we want run code if a condition or a particular case is true. This is done by:
				1. If Else Statements
					if else ladder with conditions
				2. Switch Cases
					Switch with int as an variable whose value we check by cases.
					If we don't put break then it will make switch on for all further cases as condition becomes true.
		3. Loop Structures:
			It is for one condition, if condition remains true the loop continues, and as it become false loop breaks.
				1. For Loops:
					Syntax:
					for (initialisation; condition; updation)
					{
						C++ Statements;
					}
				2. While Loops:
					Syntax:
					while(condition)
					{
						C++ Statements;
					}
				3. Do-While Loops:
					Speciality is that this loop will run for once even if condition is false.
					Syntax:
					do
					{
						C++ Statements;
					}while(condition)
	*/

    cout << "if-else ladder:\nTo check for divisibility of a by b\n";
    if ((a / b) == 0)
    {
        cout << "a is divisible by b\n\n";
    }
    else if (b != 0)
    {
        cout << "a is not divisible by b\n\n";
    }
    else
    {
        cout << "b is zero, hence a/b is undefined!\n\n";
    }

    cout << "Switch Cases:\n";
    switch (int(a))
    {
    case 2:
        cout << "a is 2\n\n";
        break;

    case 3:
        cout << "a is 3\n\n";
        break;

    default:
        cout << "Not a specified case!\n\n";
        break;
    }

    int n;
    int i;
    cout << "For Loop:\nThis loop is for printing table of given number: ";
    cin >> n;
    for (i = 1; i <= 10; i++)
    {
        cout << i * n << endl;
    }
    cout << "\n";

    /* Infinite For Loop:
	Precaution: Never try to run it for a long time it can damage you memory!
	for (initialisation; true; updation)
	{
		C++ Statements
	}
	*/

    cout << "While Loop:\nThis loop is alternative for printing table of given number: ";
    cin >> n;
    i = 1;
    while (i <= 10)
    {
        cout << i * n << endl;
        i++;
    }
    cout << "\n";

    /* Infinite While Loop:
	Precaution: Never try to run it for a long time it can damage you memory!
	while (true)
	{
		C++ Statements
	}
	*/

    cout << "Do-While Loop:\nTable of Number: ";
    i = 1;
    cin >> n;
    do
    {
        cout << i * n << endl;
        i++;
    } while (i <= 10);

    /* Infinite Do-While Loop:
	do
	{
		C++ Statements
	} while (true);
	*/

	cout << "Break and Continue Statements:\n";
	cout << "Break Statement:\nThis loop prints natural numbers from 0 to infinity, and there is a if statement which breaks loop if i = 10\n";
	for (i = 1; true; i++)
	{
		cout << i << endl;
		if (i == 10)
		{
			break;
		}
	}

	cout << "Continue Statement:\nThis loop prints natural numbers from 0 to 10, and there is a if statement which doesn't let it print even numbers\n";
	for (i = 1; i <= 10; i++)
	{
		if ((i % 2) == 0)
		{
			continue;
		}
		cout << i << endl;
	}
	cout << "\n";

	/* Derived Data Types:
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
		if (i == 4)
		{
			cout << "\n";
		}
	}

	/* User defined Data Types:
	Arrays limits the data type to one, that's why user defined variables are defined.
		1. Struct: Different variables in one array.
		2. Union: Optimised Struct, as we can use only one data type from all made.
		3. Enum: It will give index from 0 to our array.
	*/

	prsn p1;
	p1.name = "Aditya";
	p1.age = 17;
	p1.salary = 0.00000000000000001;
	p1.gender = male; // enum used

	cout << "Person p1's info:\nName: " << p1.name << "\nAge: " << p1.age << "\nSalary: " << p1.salary << "\nGender: " << p1.gender;

	union money m1;
	m1.RiceBags = 10;

	cout << "Functions and Function Prototype\n";
	/* Types of functions:
		1. void func(): without any return value
		2. int func(): it can return any integer value
	*/

	greet();

	int num1, num2;

	cout << "Enter value of num1 and num2\n";
	cin >> num1 >> num2;
	cout << "The sum of num1 and num2 is " << sum(num1, num2) << "\n\n"; // num1, num2 are actual parameters.

	cout << "Call by Value, and by reference\n";
	/* When we call a function like func(*args) we call it by value, means we make a copy of them in new memory with 
	new name then proceed operations or whatever we want to do then function return same value at end if we return 
	both a and b. To override this copying we use referencing.
	*/

	int j = 10;
	int k = 20;
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

	j = 10;
	k = 20;
	cout << "Swap by Reference Variable:\n";
	SwapByReference(j, k);
	cout << "The value of j is " << j << endl;
	cout << "The value of y is " << k << "\n\n";

	cout << "Inline Functions:\n";
	cout << "When our function performs a small task and we call it multiple times, then we";
	cout << " should make it an inline function, which puts value of function after its first call.\n";
	float g, h;
	cout << "Enter value of g and h:\n";
	cin >> g >> h;
	cout << "The Product of g and h is " << product(g, h) << "\n\n";

	cout << "Default Arguments:\n";
	cout << "When we want a default value of any argument for almost all calls and any other value for specific";
	cout << " cases, then we use default arguments.\n";

	int money = 10000;
	cout << "For Normal Person:\nMoney Deposited: " << money << "\nYou will get: " << moneyInterested(money) << " after one month.\n";
	cout << "For VIP:\nMoney Deposited: " << money << "\nYou will get: " << moneyInterested(money, 1.1) << " after one month.\n\n";

	// cout << "Constant Arguments:\n";

	cout << "Recursions & Recursive Functions:\nWhen we want to perform certain task our function call itself.\n";

	cout << "Factorial of a number by a function\nEnter Number: ";
	int l;
	cin >> l;
	cout << "Factorial of number is: " << factorial(l) << "\n\n";

	cout << "nth term of fibonacci series using recursion:\nEnter the number of term: ";
	int fibnth;
	cin >> fibnth;
	cout << "Number at " << fibnth << "th term is " << fib(fibnth) << ".\n\n";

	cout << "Function Overloading:\n";
	/* When we make functions with same name but different types/numbers of args, compiler automatically detects
	the right function for every call by given types/number of args. If func call args doesn't match any
	defined function args' types or number, then only function throws error.
	*/
	cout << "Second Sum Function with three args as input:\n";
	cout << "The sum of 7, 8, 9 is " << sum(7, 8, 9) << "\n\n";

	cout << "Volume Function Overloaded:\n";
	cout << "Volume of cube of side 3 is: " << volume(3) << endl;
	cout << "Volume of cuboid of 3, 4, 5 is: " << volume(3, 4, 5) << endl;
	cout << "Volume of cylinder of radius 3, height 5 is: " << volume(3, 5) << "\n\n";

	// return 0;
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