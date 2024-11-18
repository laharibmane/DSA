#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *top = NULL; // making this a global variable
int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
        return 0;
}
int isFull(struct Node *top)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        return 1;
    }
    else
        return 0;
}
struct Node *push(struct Node *top, int data)
{
    if (isFull(top))
    {
        printf("The List is full! (||Stack Overflow||)\n");
    }
    else
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = data;
        n->next = top;
        top = n;
        return top;
    }
}
int pop(struct Node *ptr)
{
    if (isEmpty(ptr))
    {
        printf("The List is empty! (||Stack Underflow||)\n");
        return -1;
    }
    else
    {
        struct Node *n = ptr;
        top = ptr->next;
        int value = n->data;
        free(n);
        return value;
    }
}
void LinkedlistTravers(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int peek(int pos){
    struct Node *ptr = top;
    for (int i = 0; i < (pos-1) && ptr!=NULL; i++)
    {
        ptr = ptr->next;
    }
    if (ptr!=NULL)
    {
        return ptr->data;
    }
    else return -1;
}

int stackTop(struct Node *top){
    return top->data;
}
int stackBottom(struct Node *top){
    struct Node *ptr = top;
    while (ptr->next!=NULL)
    {
        ptr = ptr->next;
    }
    return ptr->data;
    
}
int main()
{
    top = push(top, 78);
    top = push(top, 21);
    top = push(top, 233);
    LinkedlistTravers(top);
    printf("\n");
    // int element = pop(top);
    // printf("The popped element from the list is %d and current list is:\n", element);
    // LinkedlistTravers(top);

    for (int i = 1; i <= 3; i++)
    {
        printf("at Position %d element: %d\n",i,peek(i));
    }
    printf("Top element of the stack will be %d\n",stackTop(top));
    printf("Bottom element of the stack will be %d\n",stackBottom(top));
    return 0;
}