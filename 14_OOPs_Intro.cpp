#include <iostream>
using namespace std;

class Binary
{
private:
    string s;
    void ChkBinary()
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s.at(i) != '0' && s.at(i) != '1')
            {
                cout << "Not a binary data!";
                exit(0);
            }
        }
    }

    void Display()
    {
        cout << "Your Binary No is: " << s << "\n\n";
    }

public:
    void GetData()
    {
        cout << "Enter the binary number: ";
        cin >> s;
        ChkBinary();
        Display();
    }

    void Exchange()
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s.at(i) == '0')
            {
                s.at(i) = '1';
            }
            else if (s.at(i) == '1')
            {
                s.at(i) = '0';
            }
        }
        cout << "Interchange of 1 and 0 is complete:\n";
        Display();
    }
};

int main()
{
    /* Object Oriented Programming (OOPs)
	All theoritical concept can be read from this link: https://www.codewithharry.com/videos/cpp-tutorials-in-hindi-20/
	Classes(Templates):
	These are advanced type of structures.
	class ClassName
	{
		Class Members:
		   - Variables
		   - Functions
        
        Access Modifiers: Access of members can be changed.(Part of Data Hiding)
		private:
            Which can be accessed by class members only or when inside the scope of class only.
		public:
            Which can be accessed everywhere.
        protected: **For Inheritance(Skip It)**
            Which is like private but inheritable further.
	}Obj1, Obj2, Obj3; <-- Object Declaration with Classes
    Important:
        Make Sure to put ';' at end of '}' of class.
        If we don't determine access modifiers then it is set to private by default.
        Defining and Using Classes is a bit tedious task but it promotes code reusability.
	*/

	cout << "Object Oriented Programming:\n";
	cout << "Classes:\n";

	Binary b1;
    /* Private Members will give error as they aren't accessible directly.
    b1.ChkBinary();
    b1.s = 10; */
    b1.GetData();
    b1.Exchange();
    return 0;
}