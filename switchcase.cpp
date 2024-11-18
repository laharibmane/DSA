#include <iostream>
using namespace std;

int main(){
    int score;
    cout<<"enter the score you got out of 10: ";
    cin>>score;

    switch (score)
    {
    case 10:
        cout<<"YOU HAVE GOT A+";
        break;
    case 9:
        cout<<"YOU HAVE GOT A";
        break;
    case 8:
        cout<<"YOU HAVE GOT B";
        break;
    case 7:
        cout<<"YOU HAVE GOT C";
        break;
    case 6:
        cout<<"YOU HAVE GOT D";
        break;
    case 5:
        cout<<"YOU HAVE GOT E";
        break;
    default:
    cout<<"you failed HAHAHAHAA";
        break;
    }
}