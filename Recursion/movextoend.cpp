#include <iostream>
using namespace std;

string moveallX(string str)
{
    if (str.length() == 0)
    {
        return "";
    }
    char ch = str[0];
    string ans = moveallX(str.substr(1));
    if (ch == 'x')
    {
        return ans+ch;
    }
    return ch+ans;
}
int main()
{
    cout << moveallX("axxbdxcefxhix");
    return 0;
}