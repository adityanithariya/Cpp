// Header files
#include <iostream>	 //Input/Output Stream
#include <iomanip>	 // For setw manipulator
using namespace std; // This is not a good practice as it will create problems in debugging.

int main()
{
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

	return 0;
}