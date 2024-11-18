#include <stdio.h>
#include <stdlib.h>
struct queue{
    int size;
    int f;
    int r;
    int *arr;
};
int isEmpty(struct queue *q){
    if (q->f == q->r)
    {
        return 1;
    }
    else return 0;
}
int isFull(struct queue *q){
    if (q->r == q->size-1)
    {
        return 1;
    }
    else return 0;
}
void enqueueR(struct queue *q,int value){
    if (isFull(q))
    {
        printf("Queue is Full!\n");
    }
    else{
        q->r++;
        q->arr[q->r] = value;
    }
}
void enqueueF(struct queue *q,int value){
    if (isFull(q)||q->f==-1)
    {
        printf("Queue is Full!\n");
    }
    else{
        q->arr[q->f] = value;
        q->f--;
    }
}
int dequeueF(struct queue *q){
    int value = -1;
    if (isEmpty(q))
    {
        printf("Queue is Empty!\n");
    }
    else{
        q->f++;
        value = q->arr[q->f];
    }
    return value;
}
int dequeueR(struct queue *q){
    int value = -1;
    if (isEmpty(q))
    {
        printf("Queue is Empty!\n");
    }
    else{
        value = q->arr[q->r];
        q->r--;
    }
    return value;
}
void displayqueue(struct queue *q){
    int i = q->f+1; 
    while (i<=(q->r))
    {
        printf("Element: %d\n",q->arr[i]);
        i++;
    }
}
int main()
{
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->size = 5;
    q->f = q->r = -1;
    q->arr = (int*)malloc(q->size*sizeof(int));

    enqueueR(q,15);
    enqueueR(q,19);
    enqueueR(q,25);
    enqueueR(q,95);
    enqueueR(q,55);
    enqueueR(q,59);

    displayqueue(q);
    printf("Element is dequeued at the front: %d\n",dequeueF(q));
    displayqueue(q);
    printf("Element is dequeued at the rear: %d\n",dequeueR(q));
    displayqueue(q);
    return 0;
}