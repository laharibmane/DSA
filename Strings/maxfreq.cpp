#include <iostream>
#include <string>
using namespace std;

int main()
{
    int maxfreq = 0;
    char currchar;
    string str = "abcacbaade";
    for (int i = 0; i < str.size(); i++)
    {
        int count = 0;
        currchar = str[i];
        for (int j = 0; j < str.size(); j++)
        {
            if (str[j] == currchar)
            {
                count++;
            }
            maxfreq = max(maxfreq,count);
        }
    }
    cout<<maxfreq<<endl;
    return 0;
}