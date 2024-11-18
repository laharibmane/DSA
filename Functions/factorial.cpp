#include <iostream>
using namespace std;

int factorial(int num){
    // if (num == 0 || num == 1)
    // {
    //     return 1;
    // }
    // else{
    //     return num * factorial(num-1);
    // }
    int factorial = 1;
    for (int i = 1; i <= num; i++)
    {
        factorial*=i;
    }
    return factorial;
    
    
}
int main(){
    int num;

    cout<<"Enter the number you want factorial of: "<<endl;
    cin>>num;

    cout<<factorial(num);
}