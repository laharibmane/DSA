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
    
    return 0;
}