#include <iostream>
#include <string>
using namespace std;

int main()
{

    string str = "lakshya";
    // converting to uppercase 
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32; // using ASCII TABLE
        }
    }
    cout<<str<<endl;

    // lowercase 
     for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32; // using ASCII TABLE
        }
    }
    cout<<str;

    return 0;
}