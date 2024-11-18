#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    for (int i = 1; i <= n; i++)
    {
        int space = n-i;
        for (int j = 1; j <= space; j++)
        {
            cout<<" ";
        }
        int count = i;
        for (int j = 1; j <=i; j++)
        {
            cout<<count<<"";
            count--;
        }
        int count2 = 2;
        for (int j = 1; j <= i-1; j++)
        {
            cout<<count2<<"";
            count2++;
        }
        
        
        cout<<endl;
    }
    
}