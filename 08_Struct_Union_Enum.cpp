#include <iostream>
using namespace std;

typedef struct person
{
    int age;
    string name;
    float salary;
    bool gender;
}prsn;

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

int main()
{
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

    return 0;
}