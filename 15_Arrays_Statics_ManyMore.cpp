#include <iostream>
using namespace std;

class Shop
{
    static int TotalItems; // Static Variable Declaration.
    int ItemId[100];
    int ItemPrice[100];
    int TotalPrice;
    int NewItems;
    int counter=0;

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

int main()
{
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

    return 0;
}