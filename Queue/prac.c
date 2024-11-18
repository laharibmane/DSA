#include <stdio.h>
#include <stdlib.h>
struct queue{
    int f;
    int r;
    int size;
    int *arr;
};
int isEmpty(struct queue *q){
    if (q->f == q->r)
    {
        return 1;
    }
    else{
        return 0;
    }   
}
int isFull(struct queue *q){
    if (q->r == q->size-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}
void enqueue(struct queue * q,int data){
    if (isFull(q))
    {
        printf("Queue is Full!");
    }
    else{
        q->r++;
        q->arr[q->r] = data;
    }
}
int dequeue(struct queue *q){
    int value = -1;
    if (isEmpty(q))
    {
        printf("Queue is empty!\n");
    }
    else{
        q->f++;
        value = q->arr[q->f]; 
    }
    return value;
}
void queuetraverse(struct queue *q){
    int temp = q->r;
    while (temp!=-1)
    {
        printf("%d ",q->arr[temp]);
        temp--;
    }
    
}
int main()
{
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->size = 100;
    q->f = -1;
    q->r = -1;
    q->arr = (int *)malloc(q->size*sizeof(int));
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    enqueue(q,5);

    queuetraverse(q);
    printf("\n");

    printf("Deleted Value: %d\n",dequeue(q));
    printf("Deleted Value: %d\n",dequeue(q));
    return 0;
}