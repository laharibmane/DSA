#include <iostream>
using namespace std;

int main()
{
    cout << "Enter the number you want to find in the given matrix:" << endl;
    int x;
    cin >> x;

    int n, m;
    cout<<"Enter the rows and columns: ";
    cin >> n >> m;

    cout << "Please enter the elements in a sorted manner for your array: " << endl;
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int row = 0;
    int column = m - 1;
    while (row < n && column > 0)
    {
        if (arr[row][column] == x)
        {
            cout << "The given element is present in the matrix at: " << endl;
            cout << row << " " << column;
            break;
        }
        else if (arr[row][column] > x)
        {
            column = column - 1;
        }
        else
        {
            row++;
        }
    }
    return 0;
}