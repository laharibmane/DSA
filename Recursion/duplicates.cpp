#include <iostream>
using namespace std;
string removeDuplicate(string str){
    if (str.length() == 0)
    {
        return " ";
    }
    char ch = str[0];
    string ans = removeDuplicate(str.substr(1));
    if (ans[0] == ch)
    {
        return ans;
    }
    return ch+ans;
}
int main(){

    cout<<removeDuplicate("aaaabbbeeeecdddd");
    return 0;
}