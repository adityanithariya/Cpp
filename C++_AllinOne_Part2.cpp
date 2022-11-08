#include <iostream>
using namespace std;

// Class 1:
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

// Class 2:
class Shop
{
    static int TotalItems; // Static Variable Declaration.
    int ItemId[100];
    int ItemPrice[100];
    int TotalPrice;
    int NewItems;
    int counter = 0;

    void DisplayDetails();

    friend void TotalPrice(Shop, Shop, Shop); // Friend Function Declaration.

public:
    void SetDetails();
    static void DisplayTotal() // Static Method, can only be made inside class.
    {
        cout << "Number of Total Items Added in all Shops is " << TotalItems << "\n";
    }

    void FinalList(Shop obj1, Shop obj2, Shop obj3)
    {

        if (TotalItems != 0)
        {
            cout << "List of Items Added:\n";
        }

        for (int i = 0; i < obj1.NewItems; i++)
        {
            cout << "The Price of Item with ItemId " << obj1.ItemId[i] << " is " << obj1.ItemPrice[i] << endl;
        }
        for (int i = 0; i < obj2.NewItems; i++)
        {
            cout << "The Price of Item with ItemId " << obj2.ItemId[i] << " is " << obj2.ItemPrice[i] << endl;
        }
        for (int i = 0; i < obj3.NewItems; i++)
        {
            cout << "The Price of Item with ItemId " << obj3.ItemId[i] << " is " << obj3.ItemPrice[i] << endl;
        }

        cout << "\n";
    }
};

void Shop ::SetDetails()
{
    cout << "New Items: ";
    cin >> NewItems;
    cout << "\n";
    TotalPrice = 0;
    TotalItems = TotalItems + NewItems;
    for (int i = 0; i < NewItems; i++)
    {
        cout << "Enter the Item Id of Item No." << counter + 1 << " : ";
        cin >> ItemId[counter];
        cout << "Enter the Item Price: ";
        cin >> ItemPrice[counter];
        cout << "\n";
        counter++;
    }
    if (NewItems != 0)
    {
        DisplayDetails();
    }
}

void Shop ::DisplayDetails()
{
    cout << "List of Items Added:\n";

    for (int i = 0; i < counter; i++)
    {
        cout << "The Price of Item with ItemId " << ItemId[i] << " is " << ItemPrice[i] << endl;
        TotalPrice += ItemPrice[i];
    }

    cout << "\n\n";
}

int Shop ::TotalItems; //Default Value of Static Var is 0, can be modified here only.

// Friend Function of class Shop. It can access private data of Shop.
void TotalPrice(Shop obj1, Shop obj2, Shop obj3)
{
    cout << "The Total Price of all Items is " << obj1.TotalPrice + obj2.TotalPrice + obj3.TotalPrice << "\n\n";
}

// Predeclaration of Calculator class to give friend declaration in Complex class.
class Calculator;

class Complex
{
    float a, b;
    string Operation;
    string name;

    // Making class's function as friend
    // friend int Calculator :: SumRealComp(Complex, Complex);
    // friend int Calculator :: SumImgComp(Complex, Complex);

    // Making class as friend.
    friend class Calculator;

public:
    // Constructor of Complex Class
    Complex(float, float, string, string);
    Complex(const Complex &, string);
    Complex(string);

    void PrintComp(string op = "None")
    {
        if (op != "None" && name != "None")
        {
            cout << "\nBy " << op << " of z1 and z2:\n"
                 << name << " = " << a << " + " << b << "i\n";
        }
        else if (name != "None")
        {
            cout << name << " = " << a << " + " << b << "i\n\n";
        }
        else
        {
            cout << a << " + " << b << "i\n\n";
        }
    }

    void SetName(string name)
    {
        // Explicit Initialisation of Class Variable
        this.name = name;
    }
};

// Constructor Overloading
Complex ::Complex(float x, float y, string givnname = "None", string operation = "None")
{
    a = x;
    b = y;
    name = givnname;
    PrintComp(operation);
}
Complex ::Complex(const Complex &obj, string givnname = "None")
{
    a = obj.a;
    b = obj.b;
    name = givnname;
    PrintComp();
}
Complex ::Complex(string givnname = "None")
{
    a = 0;
    b = 0;
    name = givnname;
    PrintComp();
}

class Calculator
{
public:
    float SumRealComp(Complex const &obj1, Complex const &obj2)
    {
        return (obj1.a + obj2.a);
    }
    float SumImgComp(Complex const &obj1, Complex const &obj2)
    {
        return (obj1.b + obj2.b);
    }
    float DiffRealComp(Complex const &obj1, Complex const &obj2)
    {
        return (obj1.a - obj2.a);
    }
    float DiffImgComp(Complex const &obj1, Complex const &obj2)
    {
        return (obj1.b - obj2.b);
    }
    float ProdRealComp(Complex const &obj1, Complex const &obj2)
    {
        return (obj1.a * obj2.a);
    }
    float ProdImgComp(Complex const &obj1, Complex const &obj2)
    {
        return (obj1.b * obj2.b);
    }
    float DivRealComp(Complex const &obj1, Complex const &obj2)
    {
        return (obj1.a / obj2.a);
    }
    float DivImgComp(Complex const &obj1, Complex const &obj2)
    {
        return (obj1.b / obj2.b);
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
    cout << "\n";

    /* Arrays, Memory Allocation and Statics in Classes:
    Arrays:
        We can make and use arrays as private or as public(same as normal one).
    Memory allocation:
        As we know classes are templates and they have no place in memory when made.
        There are some optimisation in members' memory allocation.
        For those members which work similarly or common for all objects are made once and at the time of class formation,
        and all other things which are unique of each object are stored seperately.
    Statics(Static Variable, Static Method(func)):
        Static Var:
            static datatype varname;
            This can be modified by all objects, and can be accessed using class.
        Static Method:
            This is accessible using class only, and can only use or modify static variables.
            static void funcname()
            {
                Static Variables Only!
            }
    */
    cout << "Arrays in Classes:\nThis class adds item to the Shop Objects.\n";

    Shop MyShop1, MyShop2, MyShop3, AllShops;

    MyShop1.SetDetails();
    MyShop2.SetDetails();
    MyShop3.SetDetails();

    Shop ::DisplayTotal(); //Accessing Static Method

    // Array of Objects
    // Shop Ar1[5]; //This will create 5 objects.

    TotalPrice(MyShop1, MyShop2, MyShop3); // This is a friend function.

    AllShops.FinalList(MyShop1, MyShop2, MyShop3); // Objects as arguments in function

    cout << "Friend Class, Constructor, ConsOverloading: \n\nUsing Complex and Calculator Class:\n";
    /* Constructors:
        If we want to set value of variables of class within making the object, we use constructors.
        Syntax:
        It is same like a function without any return type and with same name as of class.
         - Parameterised Constructors:
            ClassName(args);
         - Default Constructors:
            Passing a default arg.
            ClassName(args, DefaultOne=DefaultValue);
         - Dynamic Initialisation:
            Change of datatype of args.
            ClassName(datatype1);
            ClassName(datatype2);
         - Copy Constructor:
            To make a copy of another object(z1) at the time of making object(z7).
            Here we take reference of passed object in our constructor.
         - Initialisation List:
            ClassName(args):data1(arg1), data2(arg2);
            This will set value of arg1 to data1, and value of arg2 to data2.
            Here value will set according to order of declaration in class.
            Special Case(Example for above line):
                If we have class and cons. be like:
                class ClassName
                {
                    int a;
                    int b;

                public:
                    ClassName(int i, int j):b(j), a(i+b){code}
                }
                In this class value of b will be garbage till a is initialised.
                So, a = i + {{Garbage-Value}}
       Destructors:
        When we want to perform a specific task at destruction of our object we make destructors.
        Like freeing Dynamic memory used by that object.
        Syntax:
            It is same like constructors but with a tilt(~) at starting of class name.
            Be like: ~ClassName();
    */
    Complex z1(3, 5, "z1"), z2(4, 4, "z2");

    Calculator calc;

    Complex z3(calc.SumRealComp(z1, z2), calc.SumImgComp(z1, z2), "z3", "Sum");
    Complex z4(calc.DiffRealComp(z1, z2), calc.DiffImgComp(z1, z2), "z4", "Diff");

    // This is a block of code which will destroys all data types inside it when it ends.
    {
        Complex z5(calc.ProdRealComp(z1, z2), calc.ProdImgComp(z1, z2), "z5", "Product");
        Complex z6(calc.DivRealComp(z1, z2), calc.DivImgComp(z1, z2), "z6", "Division");
    }

    cout << "\nCopy Constructor:\n";
    Complex z7(z1, "z7"); // Copy Constructor Called.

    // This will show Ambiguous Behaviour sometimes.
    // cout << "Type 2:\n";
    // Complex z9 = Complex(z2, "z9");

    cout << "Initialisation of z9:\n";
    Complex z8("z8");

    cout << "Copying Object z3 in z9:\n";
    z8 = z3; // Copy Constructor is not called.

    z8.SetName("z8");
    z8.PrintComp();

    return 0;
}