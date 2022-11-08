#include <iostream>
using namespace std;

// Recursive Function
// Factorial of a Number
int factorial(int n)
{
    static int temp = 1;
    temp = (temp * n);
    --n;
    if (n != 1)
    {
        factorial(n);
    }
    return temp;
}

// Nth term of Fibonacci Series
int fib(int n)
{
    if (n < 2)
    {
        return 1;
    }
    return fib(n - 2) + fib(n - 1);
}

int main()
{
    cout << "Recursions & Recursive Functions:\nWhen we want to perform certain task our function call"
         << "itself.\n";
    cout << "Factorial of a number by a function\nEnter Number: ";
    int fibnth;
    cin >> fibnth;
    cout << "Factorial of number is: " << factorial(fibnth);

    cout << "nth term of fibonacci series using recursion:\nEnter the number of term: ";
    int fibnth;
    cin >> fibnth;
    cout << "Number at " << fibnth << "th term is " << fib(fibnth) << "\n";

        return 0;
}