#include <iostream>
using namespace std;

inline float product(float x, float y)
{
    int z = x * y;
    return z;
}

int moneyInterested(int moneyRecieved, float factor = 1.08)
{
    return (moneyRecieved * factor);
}

// int strlen(const char a) // When we will do something with 'a' then there is a chance that 'a' will change.
// To prevent that we use constant.

int main()
{
    cout << "Inline Functions:\n";
    2 cout << "When our function performs a small task and we call it multiple times, then we";
    cout << " should make it an inline function, which puts value of function after its first call.\n";
    float a, b;
    cout << "Enter value of a and b:\n";
    cin >> a >> b;
    cout << "The Product of a and b is " << product(a, b);

    cout << "Default Arguments:\n";
    cout << "When we want a default value of any argument for almost all calls and any other value for specific";
    cout << " cases, then we use default arguments.\n";

    int money = 10000;
    cout << "For Normal Person:\nMoney Deposited: " << money << "\nYou will get: " << moneyInterested(money) << " after one month.\n";
    cout << "For VIP:\nMoney Deposited: " << money << "\nYou will get: " << moneyInterested(money, 1.1) << " after one month.\n";

    // cout << "Constant Arguments:\n";

    return 0;
}