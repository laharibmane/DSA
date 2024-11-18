#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter the number you want to check is prime or not: ";
    cin >> num;
    int count = 0;

    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            count++;
        }
    }
    if (count > 2)
    {
        cout << "The given number is not prime";
    }
    else
        cout << "Given number is prime";
}