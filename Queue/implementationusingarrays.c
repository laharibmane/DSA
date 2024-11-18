#include <stdio.h>
#include <stdlib.h>
struct queue{
    int size;
    int f;
    int r;
    int *arr;
};
int isFull(struct queue *q){
    if (q->r == q->size-1)
    {
        return 1;
    }
    else return 0;
}
int isEmpty(struct queue *q){
    if (q->r == q->f)
    {
        return 1;
    }
    else return 0;
}
void enqueue(struct queue *q,int value){
    if (isFull(q))
    {
        printf("This queue is full!\n");
    }
    else{
        q->r++;
        q->arr[q->r] = value;
    }
}
int dequeue(struct queue *q){
    int a = -1;
    if (isEmpty(q))
    {
        printf("The queue is empty!\n");
    }
    else{
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}
int main()
{
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->size = 100;
    q->f = -1;
    q->r = -1;
    q->arr = (int *)malloc(q->size*sizeof(int));

    // Enqueue some elements!!
    enqueue(q,15);
    enqueue(q,12);
    printf("The given queue is %d\n",isEmpty(q));
    // Dequeue some elements!!
    printf("dequeuing element %d\n",dequeue(q));
    printf("dequeuing element %d\n",dequeue(q));
    printf("The given queue is %d\n",isEmpty(q));
    return 0;
}