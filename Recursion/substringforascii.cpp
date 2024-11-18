#include <iostream>
using namespace std;

void substringascii(string str , string ans)
{
    if (str.length() == 0)
    {
        cout<<ans<<endl;
        return;
    }
    char ch = str[0];
    int code = ch;
    string ros = str.substr(1);
    substringascii(ros,ans);
    substringascii(ros,ans+ch);
    substringascii(ros,ans+to_string(code));

}
int main()
{
    substringascii("AB","");
    return 0;
}