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
int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
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
    pushInStack(sp,511); // Pushed max 10 values 
    pushInStack(sp,911); // stack overflow since value of stack is 10
    printf("After pushing, Full: %d\n",isFull(sp));
    printf("After pushing, Empty: %d\n",isEmpty(sp));

    // printf("Popped %d from the stack\n",popfromStack(sp));

    // printf("%d\n",sp->arr[3]);

    return 0;
}