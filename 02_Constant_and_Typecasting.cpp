#include <iostream>
using namespace std;

int main()
{
	cout << "Constant Data Types: \n";
	const int xy = 15;
	cout << "xy = 20;\nThis will give error as xy is a const variable\n\n";

	cout << "TypeCasting: \n";
	cout << "x + x1 in int is: " << (x + x1) << endl;
	cout << "x + x1 in str is: " << (to_string(x) + to_string(x1)) << "\n\n";

	return 0;
}