#include <stdio.h>
#include <stdlib.h>

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
    else
        return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
        return 0;
}
void pushInStack(struct stack *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow... cannot add %d in stack!\n",value);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int popfromStack(struct stack *ptr){
    if (isEmpty(ptr))
    {
        printf("The stack is currently empty no more elements can be popped :)");
        return -1;
    }
    else{
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}
// PEEK
int peek(struct stack *ptr,int i){
    int arrayIndex = ptr->top-i+1;
    if (arrayIndex<0)
    {
        printf("Not a valid position for stack!\n");
        return -1;
    }
    else{
        return ptr->arr[arrayIndex];
    }
    
}
int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 15;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    pushInStack(sp,56);
    pushInStack(sp,3);
    pushInStack(sp,546);
    pushInStack(sp,96);
    pushInStack(sp,566);
    pushInStack(sp,76);
    pushInStack(sp,432);
    pushInStack(sp,5236);
    pushInStack(sp,23);
    pushInStack(sp,511);
    pushInStack(sp,69);

    // Printing values from the stack
    for (int i = 1; i <= sp->top+1; i++)
    {
        printf("The value at position %d is %d\n",i,peek(sp,i));
    }
    

    return 0;
}