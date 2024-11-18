#include <stdio.h>
int main()
{
    // Bubble Sort Algorithm
    int arr[] = {7, 11, 9, 2, 17, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int passes = 0;
    int isSorted = 1;
    while (passes <= n - 1)
    {
        isSorted = 1;
        for (int i = 0; i < n - passes; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                isSorted = 0;
            }
        }
        passes++;
    }
    printf("The sorted array will be:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}