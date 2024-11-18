#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number you want to check is power of 2 or not: " << endl;
    cin >> n;
    if (n == 0 || n == 1)
    {
        cout<<"The given number is not power of 2";
    }
    
    else if ((n & (n - 1)) == 0)
    {
        cout << "The given number is power of 2";
    }
    else
        cout << "The given number is not power of 2";
}