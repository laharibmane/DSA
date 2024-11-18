#include <stdio.h>
#include <stdlib.h>
// if stack is empty pop cannot be performed or if its full push cannot be performed
struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else return 0;
}

int isFull(struct stack *ptr){
    if (ptr->top == ptr->size-1)
    {
        return 1;
    }
    else return 0;
}
int main()
{
    // struct stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int *)malloc(s.size*sizeof(int));

    struct stack *s;
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    // pushing element manually
    // s->arr[0] = 7;
    // s->top++;
    // to check is stack is empty 
    if (isEmpty(s))
    {
        printf("The stack is empty!\n");
    }
    else printf("The stack is not empty!\n");

    // to check if stack is full
    if (isFull(s))
    {
        printf("The stack is full!\n");
    }
    else printf("The stack is not full!\n");

    return 0;
}