#include <iostream>
using namespace std;

// Predeclaration of Calculator class to give friend dec in Complex class.
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

    // Destructor of Complex Class
    ~Complex()
    {
        cout << "Destructor of " << name << " called.\n";
    }

    void PrintComp(string op = "None")
    {
        if (op != "None" && name != "None")
        {
            cout << "By " << op << " of z1 and z2:\n"
                 << name << " = " << a << " + " << b << "i\n\n";
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

    void SetName(string nm)
    {
        name = nm;
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

    // This is a block of code which will destroys all data types inside when ends.
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