#include <iostream>
#include <string>
using namespace std;

int main()
{

    string str = "lakshya";
    string str1(5, 'n');
    // cin >> str;
    cout << str1 << endl;
    cout << str << endl;
    string str2;
    getline(cin, str2);
    cout << str2;

    return 0;
}