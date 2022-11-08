#include <iostream>
using namespace std;

int main()
{
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

    return 0;
}