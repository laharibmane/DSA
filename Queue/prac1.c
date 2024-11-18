#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *f = NULL;
struct Node *r = NULL;
int isEmpty(){
    if (f == NULL)
    {
        return 1;
    }
    else return 0;
}
void enqueue(int value){
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = value;
    new->next = NULL;

    if (f == NULL)
    {
        f = r = new;
    }
    r->next = new;
    r = new;
}
int dequeue(){
    if (isEmpty())
    {
        printf("Queue is Empty!!\n");
    }
    struct Node *ptr = f;
    int val = ptr->data;
    f = f->next;
    free(ptr);

    return val; 
}
int main()
{
    enqueue(53);
    enqueue(43);
    enqueue(83);
    enqueue(65);

    printf("%d Dequeued element from the queue",dequeue());
    printf("\n%d Dequeued element from the queue",dequeue());
    
    return 0;
}