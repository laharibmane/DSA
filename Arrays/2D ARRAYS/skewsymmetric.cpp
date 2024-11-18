#include <iostream>
using namespace std;

bool isskewsymmetric(int arr[][3], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (arr[i][j] != -1*(arr[j][i]))
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
    if (isskewsymmetric(arr,n))
    {
        cout<<"Matrix is Skew Symmetric!";
    }
    else cout<<"Matrix is not Skew Symmetric!";
    
    return 0;
}