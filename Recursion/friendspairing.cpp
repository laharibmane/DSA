#include <iostream>
using namespace std;
int friendspairing(int n){
    if (n<3 && n>0)
    {
        return n;
    }
    return friendspairing(n-1) + friendspairing(n-2)*(n-1);
}
int main(){
    cout<<friendspairing(4);
    return 0;
}