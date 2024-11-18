#include <stdio.h>
#include <stdlib.h>

struct Node *f = NULL;
struct Node *r = NULL;
struct Node
{
    struct Node *next;
    int data;
};
void LinkedlistTravers(struct Node *ptr)
{
    printf("Printing the elements of this Linked List: \n");
    while (ptr!=NULL)
    {
        printf("Element: %d\n",ptr->data);
        ptr = ptr->next;
    }
}
int IsEmpty()
{
    if (f == NULL)
    {
        return 1;
    }
    else
        return 0;
}
int IsFull() 
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        return 1;
    }
    else
        return 0;
}
void enqueue(int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if(n == NULL){
        printf("Queue is Full!!\n");
    }
    n->data = data;
    n->next = NULL;
    if (f == NULL)
    {
        f = r = n;
    }
    else{
        r->next = n;
        r = n;
    }
}
int dequeue(){
    int value = -1;
    if (IsEmpty())
    {
        printf("The List is Empty!\n");
    }
    else{
        struct Node *ptr = f;
        f = f->next;
        value = ptr->data;
        free(ptr);
        return value;
    }

}
int main()
{ 
    enqueue(23);
    enqueue(43);
    enqueue(54);
    LinkedlistTravers(f);
    printf("Dequeuing element %d\n",dequeue());
    LinkedlistTravers(f);
    return 0;
}