#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *CreateNode(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;
}
struct Node *InsertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = CreateNode(data);
    struct Node *p = head;

    if (head == NULL)
    {
        return ptr;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = ptr;
    }
    return head;
}
struct Node *InsertionAtHead(struct Node *head, int data)
{
    struct Node *ptr = CreateNode(data);

    ptr->next = head;
    head = ptr;
    return head;
}
struct Node *InsetionInBetween(struct Node *head, int data, int index)
{
    int i = 0;
    struct Node *ptr = CreateNode(data);
    struct Node *p = head;
    if (index == 0)
    {
        return InsertionAtHead(head, data);
    }
    else
    {
        while (i != index - 1)
        {
            p = p->next;
            i++;
        }
        ptr->next = p->next;
        p->next = ptr;
    }
    return head;
}
struct Node *DeletionAtHead(struct Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    struct Node *ptr = head;
    head = head->next;
    free(ptr);

    return head;
}
struct Node *DeletionAtEnd(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        q = q->next;
        p = p->next;
    }
    p->next = q->next;
    free(q);

    return head;
}
struct Node *DeletionInBetweeen(struct Node *head, int index)
{
    if (index == 0)
    {
        return DeletionAtHead(head);
    }
    int i = 0;
    struct Node *ptr = head;
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    p = ptr->next;
    ptr->next = p->next;
    free(p);

    return head;
}
int LinkedListTraversal(struct Node *head)
{
    int i = 0;
    struct Node *ptr = head;
    if (head == NULL)
    {
        printf("Linked List in empty!\n");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
            i++;
        }
    }
    return i;
}
void swap(struct Node *head, int n)
{
    struct Node *ptr = head;
    int i = 0;
    while (i <= n && ptr != NULL && ptr->next != NULL)
    {
        int temp = ptr->data;
        ptr->data = ptr->next->data;
        ptr->next->data = temp;

        ptr = ptr->next->next;
        i += 2;
    }
}
int frequency(struct Node *head, int value)
{
    if (head == NULL)
    {
        return 0;
    }
    int count = 0;
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->data == value)
        {
            count++;
        }
        ptr = ptr->next;
    }
    return count;
}
struct Node *reverse(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *prev = NULL;

    while (ptr != NULL)
    {
        struct Node *temp = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = temp;
    }
    return prev; // as it becomes head
}
struct Node *reverselastfive(struct Node *head,int n){
    int lastfive = n-5;
    struct Node *ptr = head;
    struct Node *prev = NULL;

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
struct Node *RemoveDuplicates(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *prev = NULL;
    int arr[1000] = {0};

    while (ptr != NULL)
    {
        if (arr[ptr->data] == 1)
        {
            prev->next = ptr->next;
            free(ptr);

            ptr = prev->next;
        }
        else
        {
            arr[ptr->data] = 1;
            prev = ptr;
            ptr = ptr->next;
        }
    }
}
int main()
{
    struct Node *head = NULL;

    int n;
    int value;
    printf("Enter the number of nodes you want:\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the value of Node %d:\n", i);
        scanf("%d", &value);

        head = InsertAtEnd(head, value);
    }
    int m = LinkedListTraversal(head);

    // swap(head,m);

    printf("\n");
    // m = LinkedListTraversal(head);
    // head = InsetionInBetween(head,9,1);
    // LinkedListTraversal(head);

    // printf("\n");
    // head = DeletionInBetweeen(head,1);
    // LinkedListTraversal(head);
    // printf("\nEnter the value you want to check frequency for in the given list:\n");
    // int freq;
    // scanf("%d",&freq);
    // printf("%d",frequency(head,freq));

    // head = reverse(head);
    // m = LinkedListTraversal(head);

    head = InsertionAtHead(head,9);

    // reverselastfive(head,n);
    LinkedListTraversal(head);


    return 0;
}