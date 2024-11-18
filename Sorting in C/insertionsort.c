#include <stdio.h>
#include <stdlib.h>
void insertionSort(int *arr,int n){
    int key, j;
    // Loop for passes 
    for (int i = 1; i <= n-1; i++)
    {
        key = arr[i];
        j = i-1;
        // Loop for each pass
        while (arr[j]>key && j>=0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key; // if j goes to -1 index then this 
    }
    
}
int main()
{
    int arr[] = {12,54,65,7,23,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    insertionSort(arr,n);

    printf("The Array after insertion sort will be: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    
    return 0;
}