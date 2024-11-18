#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number you want to count number of ones in binary for: "<<endl;
    cin>>n;
    int count = 0;
    while (n!= 0)
    {
        n = (n & (n-1));
        count++;
    }
    cout<<count;
    
}