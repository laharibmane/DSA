#include <iostream>
using namespace std;
int swap(int *p , int *q){
    int temp = *p;
    *p = *q;
    *q = temp;
}
int main(){
    int a = 2;
    int b =4;
    swap(&a,&b);
    cout<<a<<" "<<b;
}