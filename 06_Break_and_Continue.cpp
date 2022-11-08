#include <iostream>
using namespace std;

int main()
{
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

	return 0;
}