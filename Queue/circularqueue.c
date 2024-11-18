#include <stdio.h>
#include <stdlib.h>
struct circularqueue{
    int size;
    int f;
    int r;
    int *arr;
};
int isFull(struct circularqueue *q){
    if ((q->r+1)%q->size == q->f)
    {
        return 1;
    }
    else return 0;
}
int isEmpty(struct circularqueue *q){
    if (q->r == q->f)
    {
        return 1;
    }
    else return 0;
}
void enqueue(struct circularqueue *q,int value){
    if (isFull(q))
    {
        printf("The given circular queue is full!!\n");
    }
    else{
        printf("Enqued element : %d\n",value);
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = value;
    }
}
int dequeue(struct circularqueue *q){
    int value = -1;
    if (isEmpty(q))
    {
        printf("The given circular queue is Empty!!\n");
    }
    else{
        q->f = (q->f+1)%q->size;
        value = q->arr[q->f];
        printf("Dequed element : %d\n",value);
    }
    return value;
}
int main()
{
    struct circularqueue *q = (struct circularqueue*)malloc(sizeof(struct circularqueue));
    q->size = 4+1;
    q->f = 0;
    q->r = 0;
    q->arr = (int *)malloc(q->size*sizeof(int));

    enqueue(q,65);
    enqueue(q,33);
    enqueue(q,675);
    enqueue(q,68);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    enqueue(q,65);
    enqueue(q,33);
    enqueue(q,675);
    enqueue(q,68);
    printf("%d\n",isFull(q));
    return 0;
}