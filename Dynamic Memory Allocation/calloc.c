#include <stdio.h>
#include <stdlib.h>

int main()
{

    // use of calloc

    int *ptr;
    int n;
    printf("Enter the size of ur array: \n");
    scanf("%d",&n);
    ptr = (int *)calloc(n , sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value no %d of this array:\n ",i);
        scanf("%d",&ptr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d\n",ptr[i]);
    }
    
    
    return 0;
}