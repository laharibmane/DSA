#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *createNode(int value)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = value;
    ptr->next = NULL;
    return ptr;
}
struct Node *insertAtEnd(struct Node *head, int value)
{
    struct Node *ptr = createNode(value);

    if (head == NULL)
    {
        return ptr;
    }
    else
    {
        struct Node *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = ptr;
    }
    return head;
}
void linkedlisttraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
struct Node *reverse(struct Node *head){
    struct Node *ptr = head;
    struct Node *prev = NULL;
    int i = 0;
    while (ptr!=NULL)
    {
        struct Node* temp = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = temp;
    }
    return prev; // return prev as it becomes head 
}
void reverseLastFive(struct Node *head,int n){
    struct Node *ptr = head;
    struct Node *prev = NULL;
    int lastfive = n-5;
    
    for (int i = 0; i < lastfive; i++)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    struct Node *lastFiveNodes = reverse(ptr);
    if (prev!=NULL)
    {
        prev->next = lastFiveNodes;
    }
    else{
        head = lastFiveNodes;
    }
}
int main()
{

    struct Node *head = NULL;
    int n, value;
    printf("Enter the number of nodes you want in your linked list: \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the value for Node %d: ", i);
        scanf("%d", &value);
        head = insertAtEnd(head, value);
    }
    linkedlisttraversal(head);  
    printf("\n");
    reverseLastFive(head,n);
    printf("Reversed Linked List for only last five nodes: ");
    linkedlisttraversal(head);
    return 0;
}