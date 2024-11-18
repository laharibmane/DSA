#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int num;
    cout<<"Enter a 3 digit number to check whether the number is Armstrong or not: ";
    cin>>num;

    int sum=0;
    int originalnum = num;
    while (num!=0)
    {
        sum += round(pow(num%10,3));
        num = num/10;
    }

    if (sum==originalnum)
    {
        cout<<"The given number is armstrong number";
    }
    else cout<<"The given number is not armstrong number";
    
    return 0;
    
}