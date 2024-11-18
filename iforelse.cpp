#include <iostream>
using namespace std;

int main(){
    int year;
    cout<<"enter the year you want to check is leap or not: ";
    cin>>year;

    if (year%100==0)
    {
        if (year%400==0)
        {
            cout<<"year is leap";
        }
        else cout<<"year is not leap";
    }
    else if (year%4==0)
    {
        cout<<"year is leap";
    }
    else cout<<"year is not leap";
    
}