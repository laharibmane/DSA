#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};
int isEmpty(struct stack *sp)
{
    if (sp->top == -1)
    {
        return 1;
    }
    else
        return 0;
}
int isFull(struct stack *sp)
{
    if (sp->top == sp->size - 1)
    {
        return 1;
    }
    else
        return 0;
}
void pushinStack(struct stack *sp, char data)
{
    if (isFull(sp))
    {
        printf("|| StacK Overflow ||\n");
    }
    else
    {
        sp->top++;
        sp->arr[sp->top] = data;
    }
}
char popFromStack(struct stack *sp)
{

    if (isEmpty(sp))
    {
        printf("|| Stack Underflow ||\n");
    }
    else
    {
        int value = sp->arr[sp->top];
        sp->top--;
        return value;
    }
}
int match(char a, char b)
{
    if (a == '{' && b == '}')
    {
        return 1;
    }
    else if (a == '(' && b == ')')
    {
        return 1;
    }

    else if (a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
}
int parenthesismatch(char *exp)
{
    struct stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char popped_ch;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            pushinStack(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (isEmpty(sp)) return 0;
            else
                popped_ch = popFromStack(sp);
            if (!match(popped_ch, exp[i]))
            {
                return 0;
            }
        }
    }
    if (isEmpty(sp))
    {
        return 1;
    }
    else
        return 0;
}
int main()
{

    char *exp = "(7-11 + {23-8*2}- [33+1])";
    if (parenthesismatch(exp))
    {
        printf("The parenthesis is matching!!\n");
    }
    else
    {
        printf("The parenthesis is not matching!!\n");
    }
    return 0;
}