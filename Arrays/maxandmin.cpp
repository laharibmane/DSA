#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of your array: " << endl;
    cin >> n;

    int arr[n];
    cout << "Enter the elements you want in your array: " << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int MAX = arr[0];
    int MIN = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > MAX)
        {
            MAX = arr[i];
        }
        if (arr[i] < MIN)
        {
            MIN = arr[i];
        }
    }
    cout << "The maximum and minimum element in this array will be: " << endl;
    cout << MAX << endl;
    cout << MIN << endl;
}