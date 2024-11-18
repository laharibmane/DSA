#include <iostream>
using namespace std;

bool isPrime(int num){
    int count = 0;
    for (int i = 1; i <= num; i++)
    {
        if (num%i==0)
        {
            count++;
        }
        
    }
    if (count>2)
    {
        return false;
    }
    else return true;
    
    
}
int main(){
    int a,b;

    cin>>a>>b;

    for (int i = a; i <= b; i++)
    {
       if (isPrime(i))
       {
        cout<<i<<endl;
       }
       
    }
    return 0;
}