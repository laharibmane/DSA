#include <iostream>
using namespace std;

int main()
{

    char arr[100];
    cin.getline(arr, 100);
    // cin.ignore();

    int len = 0;
    int i = 0;
    int maxlen = 0;

    while (1)
    {
        if (arr[i] == ' ' || arr[i] == '\0')
        {
            if (len > maxlen)
            {
                maxlen = len;
            }
             len = 0;
        }
        else
        {
            len++;
        }
        if (arr[i] == '\0')
        {
            break;
        }

        i++;
    }
    cout<<maxlen;
}