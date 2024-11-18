#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int length = 2;
    int pd = arr[1] - arr[0];
    int i = 2;
    int count = 2;

    while (i < n)
    {
        if (pd == arr[i] - arr[i - 1])
        {
            count++;
        }
        else
        {
            pd = arr[i] - arr[i - 1];
            count = 2;
        }
        length = max(length, count);
        i++;
    }
    cout << length << endl;

    return 0;
}