#include <iostream>
using namespace std;

bool issymmetric(int arr[][3], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (arr[i][j] != arr[j][i])
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int n = 3;

    int arr[3][3];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    if (issymmetric(arr,n))
    {
        cout<<"Matrix is Symmetric!";
    }
    else cout<<"Matrix is not Symmetric!";
    
    return 0;
}