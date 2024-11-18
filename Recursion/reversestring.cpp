#include <iostream>
using namespace std;
void reverse(string str,int i){
    if (i >= str.length())
    {
        return;
    }
    
    reverse(str,i+1);
    cout<<str[i];
}
int main(){
    string str = "binod";
    reverse(str,0);
    return 0;
}