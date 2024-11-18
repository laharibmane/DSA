#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("Enter the size of your array:\n");
    scanf("%d",&n);

    int A[n];
    printf("Enter elements of your array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&A[i]);
    }
    int B[n];
    for (int i = 0; i < n; i++)
    {
        B[A[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        A[i] = B[i];
    }
    printf("Transformed array will be:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",A[i]);
    }
    
    
    
    
    
    
    return 0;
}