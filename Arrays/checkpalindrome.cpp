#include <iostream>
#include <cstring>
using namespace std;

int main()
{

    char arr[100];
    cin >> arr;
    char revarr[100] = {'\0'};
    int j = 0;
    while (arr[j] != '\0')
    {
        revarr[j] = arr[j];
        j++;
    }
    int len = 0;
    while (arr[len] != '\0')
    {
        len++;
    }

    for (int i = 0; i < len; i++)
    {
        char temp = revarr[i];
        revarr[i] = revarr[len - i - 1];
        revarr[len - i - 1] = temp;
    }

    if (strcmp(arr, revarr) == 0)
    {
        cout << "The input is a palindrome!";
    }
    else
        cout << "It is not a palindrome!";

    return 0;
}