#include <iostream>
using namespace std;

int main(){

    int n;
    cin>>n;
    
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int sum = 0;
    int maxsum = 0;
    for (int i = 0; i < n; i++)
    {
        sum+= arr[i];
        if (sum<0)
        {
            sum = 0;
        }
        if (sum>maxsum)
        {
            maxsum = sum;
        }
    }
    cout<<maxsum<<endl;
    
    return 0;
}