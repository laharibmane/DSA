#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){

    string s = "247348724";
    sort(s.begin(), s.end(), greater<char>());
    cout<<s<<endl;
    return 0;
}