#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    char *arr;
};
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
        return 0;
}
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
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
        printf("||Stack Overflow||\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}
char popFromStack(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("||Stack Underflow||\n");
    }
    else
    {
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}
char stackTop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}
// precence function
int precedence(char ch)
{
    if (ch == '^')
    {
        return 3;
    }

    if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    return 0;
}
// is operator or not!!
int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
    {
        return 1;
    }
    else
        return 0;
}
// Infit to Postfix function....
char *infixTopostfix(char *infix)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 50;
    sp->top = -1;
    sp->arr = (int *)malloc(sizeof(int) * sp->size);

    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stackTop(sp)))
            {
                pushInStack(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = popFromStack(sp);
                j++;
            }
        }
    }
}
int main()
{
    char *infix = "A+B*C-D/E^F*G*H";
    ;
    printf("postfix expression of given infix expression will be: %s\n", infixtopostfix(infix));

    return 0;
}