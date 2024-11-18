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
struct Node *insertAtEnd(struct Node *head,int value){
    struct Node *ptr = createNode(value);

    if (head == NULL)
    {
        return ptr;
    }
    else{
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
void swapnodes(struct Node *head, int l)
{
    struct Node *ptr = head;
    int i = 0;
    while (i <= l && ptr != NULL && ptr->next != NULL)
    {
        int temp = ptr->data;
        ptr->data = ptr->next->data;
        ptr->next->data = temp;

        ptr = ptr->next->next;
        i += 2;
    }
}
int main()
{
    
    struct Node *head = NULL;
    int n,value;
    printf("Enter the number of nodes you want in your linked list: \n");
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the value for Node %d: ",i);
        scanf("%d",&value);
        head = insertAtEnd(head,value);
    }
    linkedlisttraversal(head);

    printf("\n");
    swapnodes(head, n);
    linkedlisttraversal(head);
    return 0;
}