#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter the rows and columns for your matrix: " << endl;
    cin >> n >> m;
    int arr[n][m];

    cout << "Enter the elements of your matrix: " << endl;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "Enter the element you want to search in your matrix: " << endl;
    int x;
    cin >> x;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i][j] == x)
            {
                cout << "Element found at: ";
                cout << i << " , " << j;
            }
            else cout<<"Element not found!";
        }
    }
}