#include <stdio.h>
#include <stdlib.h>
void SelectionSort(int *arr,int n){
    int indexofmin;
    for (int i = 0; i < n-1; i++)
    {
        indexofmin = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j]<arr[indexofmin])
            {
                indexofmin = j;
            }
        } // swap arr[i] and arr[indexofmin]
        int temp = arr[i];
        arr[i] = arr[indexofmin];
        arr[indexofmin] = temp;
    }
}
int main()
{
    int arr[] = {3,5,2,13,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    SelectionSort(arr,n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    
    return 0;
}