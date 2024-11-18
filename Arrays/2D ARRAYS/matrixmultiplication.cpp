#include <iostream>
using namespace std;

int main()
{
    int m, n;
    cout << "Enter the rows and columns for the first matrix: " << endl;

    cin >> m >> n;
    int matrix1[m][n];

    cout << "Enter the elements for your first matrix: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix1[i][j];
        }
    }
    cout << "Your first matrix is: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix1[i][j] << " ";
        }
        cout << endl;
    }

    int p, q;
    cout << "Enter the rows and columns for the second matrix: " << endl;

    cin >> p >> q;
    int matrix2[p][q];

    cout << "Enter the elements for your second matrix: " << endl;
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            cin >> matrix2[i][j];
        }
    }
    cout << "Your second matrix is: " << endl;
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }
    if (n != p)
    {
        cout << "Matrix multiplication is not possible!";
    }
    else
    {
        int result[m][q] = {0};
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < q; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
        cout << "So the matrix multiplication product will be: " << endl;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < q; j++)
            {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}