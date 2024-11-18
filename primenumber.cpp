#include <iostream>
using namespace std;

int main(){
    // to check if a number is prime or not

    // int num;
    // cin>>num;
    // int count = 0;
    // for (int i = 1; i <= num; i++)
    // {
    //     if (num%i==0)
    //     {
    //         count++;
    //     }
    // }
    //    if (count>2)
    //    {
    //     cout<<"the number is not prime";
    //    }
    //    else cout<<"number is prime";

     // using break statement
   int i;
   int num;
   cin>>num;
    for ( i = 2; i < num; i++)
    {
        if (num%i==0)
        {
            cout<<"number is not prime";
            break;
        }
    }
    if (i==num)
    {
       cout<<"number is prime";
    }     
}