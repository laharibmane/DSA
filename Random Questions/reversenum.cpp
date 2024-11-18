#include <iostream>
using namespace std;

int main()
{
    int num;
    cout<<"Enter the number you want to reverse: "<<endl;
    cin>>num;
    int reversenum=0;
    while (num!=0)
    {
        reversenum = reversenum*10 + num%10;
        num = num/10;
    }

    cout<<"The reverse of the given number is: "<<reversenum;    
}