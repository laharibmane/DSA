#include <iostream>
using namespace std;

int main(){
    int n = 7;
    int arr[7]= {1,2,3,4,1,2,3};
    int xorsum = 0;
    for (int i = 0; i < 7; i++)
    {
        xorsum = xorsum^arr[i];
    }
    cout<<xorsum;
    
}