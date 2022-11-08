/* Inheritance:
    When we want to get features(data and methods) from a previously defined class to a new class
    then we use inheritance. In an Inheritance, we can inherit public and protected members only.
    We will see example of Hybrid Inheritance which will cover all types of Inheritances.

    Basic terminology:
        1. Base Class: Class from which a class is derived.
        2. Derived Class: Class which is derived from another class.
        3. Arrow Convention:
            Class A --> Class B means class B is derived from class A.(We used)
            Class A <-- Class B means class A from which class B is derived.
        4. visibility mode: It defines in which access type we want to inherit members of base
        class. By default visibility is set to private if we don't specify it.
        Table for different visibility with different access modifiers in base class.
            Members/Visibility-->   Private      Public      Protected
        1. Private             Not Inherited Not Inherited Not Inherited
        2. Public                  Private      Public      Protected
        3. Protected               Private     Protected    Protected

    Types of Inheritance:
        1. Single Inheritance: One Derived Class from One Base Class.
            Class A --> Class B
        2. MultiLevel Inheritance: When there is a chain of Single Inheritance.
            Class A --> Class B --> Class C.
        3. Multiple Inheritance: When a class is derived from multiple classes.
            Class A, B... --> Class D
        4. Hierarchical Inheritance: When two classes are derived from one Base Class.
            Class A --> Class B, C...
        5. Hybrid Inheritance: It is mixture of Hierarchical, Multiple Inheritance and
        shows like multilevel Inheritance.
            Class A, B --> Class C --> Class D, E

    Syntax of Inheritance: Let there are classes A, B, C...
        class {{Derived-class}} : {{visibility-mode}} {{Base-class}}, {{vm}} {{Base}},...
        {
            Class Body;
        };

    Ambiguity in Inheritance:
        When we have methods with same names in two or more than two base classes then we have to
        specify that which class's method will be called when we call that function from our
        derived class.
        Syntax for resolving ambiguity:
            {{return-type}} {{ambiguous-method-name}}()
            {
                {{BaseClassName}}::{{ambiguous-method-name}}();
            }

    Virtual Base Class for Diamond Inheritance:
        When we are dealing with inheritance such that:
            Class A --> Class B, C --> Class D
        then there is a chance that flow of members will create a problem as there will be two
        copies methods in Class D which are from Class A. This will create problem for compiler
        here will inherit Class B and C with a special method which is virtual method which will
        tell Class B and C to send one copy from any one.
        Syntax:
            Same as of Inheritance but with 'virtual' keyword after ':' when inheriting.
    
    Constructors:
        When we inherit by any type if we have or havn't constructor of derived class,
        constructor of first base class will be called(if any).
        Special Syntax:
            We can take args for constructors of base classes(as we give values to data types) by using following:
            {{DerivedClassName}}(args):{{BaseClass1}}(arg1), {{BaseClass2}}(arg2)
            {
                Constructor Code;
            }

    Hybrid Inheritance Example:
        Class FoodItems --> Class Menu, Order --> Class Restaurant
*/

#include <iostream>
#include <fstream> // File Stream
#include <stdlib.h>
using namespace std;

class FoodItems
{
    string Ingredients[50];

public:
    string FoodName[50];
    int ItemPerPlate[50];
    FoodItems()
    {
        SetFoodData();
    }

protected:
    int ItemPrice[50];
    int TotalFoodItems = 0;
    void getIngredients()
    {
        for (int i = 0; i < TotalFoodItems; i++)
        {
            cout << FoodName[i] << ": " << Ingredients[i] << endl;
        }
    }
    void SetFoodData()
    {
        int NewItems;
        cout << "Add Food Items:\nTotal New Items: ";
        cin >> NewItems;
        if (NewItems != 0)
        {
            cout << "\nMake Sure that No Spaces Allowed Here!\n";
        }
        int PresentFoodItems = TotalFoodItems;
        for (int i = TotalFoodItems; i < (PresentFoodItems + NewItems); i++)
        {
            cout << "Item No.: " << (i + 1) << endl;
            cout << "Enter Food Name: ";
            getline(cin >> ws, FoodName[i]);
            cout << "Enter Item Per Plate(if any, else 1): ";
            cin >> ItemPerPlate[i];
            cout << "Enter Ingredients: ";
            getline(cin >> ws, Ingredients[i]);
            cout << "\n";
            TotalFoodItems++;
        }
    }
};

class Menu : virtual public FoodItems
{
protected:
    void SetPriceList()
    {
        system("CLS");
        for (int i = 0; i < TotalFoodItems; i++)
        {
            cout << "Item No.: " << (i + 1) << endl
                 << "Food Item: " << FoodName[i] << endl
                 << "Item Per Plate: " << ItemPerPlate[i] << endl
                 << "Enter Item Price: ";
            cin >> ItemPrice[i];
            cout << "\n";
        }
    }

public:
    void PrintMenu()
    {
        for (int i = 0; i < TotalFoodItems; i++)
        {
            cout << "Item No.: " << (i + 1) << endl
                 << "Food Item: " << FoodName[i] << endl
                 << "Item Per Plate: " << ItemPerPlate[i] << endl
                 << "Item Price: " << ItemPrice[i] << endl
                 << endl;
        }
    }
    Menu()
    {
        SetPriceList();
    }
};

class Order : virtual public FoodItems
{
public:
    int OrderNo = 0;

protected:
    int OrderList[50][50];
    void TakeOrder()
    {
        cout << "Order:\nTo End Order List give 0 as Item No.\n";
        int i = 0;
        do
        {
            cout << "Enter Item No. from Menu: ";
            cin >> OrderList[i][OrderNo];
            OrderList[i][OrderNo] -= 1;
            if (OrderList[i][OrderNo] == -1)
            {
                break;
            }
            i++;
        } while (true);
        if (OrderList[0] != 0)
        {
            OrderNo += 1;
        }
        for (i = 0; OrderList[i][OrderNo] != 0; i++)
        {
            ofstream out;
            out.open("Order" + to_string(OrderNo + 1) + ".txt");
            for (int i = 0; OrderList[i][OrderNo] != 0; i++)
            {
                cout << "Items Ordered:\n"
                     << "Item No.: " << (OrderList[i][OrderNo] + 1) << endl
                     << "Food Item: " << FoodName[OrderList[i][OrderNo]] << endl
                     << "Item Per Plate: " << ItemPerPlate[OrderList[i][OrderNo]] << endl
                     << "Item Price: " << ItemPrice[OrderList[i][OrderNo]] << endl
                     << endl;
            }
            out.close()
        }
    }
};

class Restaurant : public Menu, public Order
{
    string RestaurantPapers;

public:
    int Ratings;
    string RestaurantName;
    void RestaurantDetails()
    {
        system("CLS");
        cout << "Restaurant Name: " << RestaurantName << endl
             << "Restaurant Ratings: " << Ratings << "\n\n";
    }

    void PauseNClear()
    {
        do
        {
        } while (cin.get() != '\n');
        system("CLS");
    }

    Restaurant(string Name, int Rating)
    {
        RestaurantName = Name;
        Ratings = Rating;
        string Input;
        while (true)
        {
            if (Input != "menu")
            {
                RestaurantDetails();
            }

            getline(cin >> ws, Input);
            if (Input == "menu")
            {
                PrintMenu();
            }
            else if (Input == "order")
            {
                cout << "Order No.: " << (OrderNo + 1) << endl;
                TakeOrder();
                PauseNClear();
            }
            else if (Input == "ingredients")
            {
                getIngredients();
                PauseNClear();
            }
            else if (Input == "add items")
            {
                SetFoodData();
            }
            else if (Input == "pay")
            {
                int OrderPayNo;
                cout << "Enter Order No.: ";
                cin >> OrderPayNo;
                OrderPayNo -= 1;
                for (int i = 0; OrderList[i][OrderPayNo] != 0; i++)
                {
                    cout << "Items Ordered:\n"
                         << "Item No.: " << (OrderList[i][OrderPayNo] + 1) << endl
                         << "Food Item: " << FoodName[OrderList[i][OrderPayNo]] << endl
                         << "Item Per Plate: " << ItemPerPlate[OrderList[i][OrderPayNo]] << endl
                         << "Item Price: " << ItemPrice[OrderList[i][OrderPayNo]] << endl
                         << endl;
                }
                PauseNClear();
            }
            else
            {
                cout << "Invalid Input!" << endl;
                PauseNClear();
            }
        }
    }
};

int main()
{
    Restaurant BitsNBites("Bits N Bites", 9);
    return 0;
}