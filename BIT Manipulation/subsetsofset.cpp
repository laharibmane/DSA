#include <iostream>
using namespace std;

int main()
{
    int arr[4] = {1, 2, 3, 4};
    int n = 4;
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                cout << arr[j] << " ";
            }
        }
        cout<<endl;
    }
}