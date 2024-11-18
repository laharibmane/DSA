#include <stdio.h>
#include <stdlib.h>
// case 4 - Deletion of Node with a given value
struct Node
{
    int data;
    struct Node *next;
};

void LinkedlistTravers(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *DeletionatValue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->data!=value && q->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    
    return head;
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    // Allocate memory for nodes in the linked list in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    //  Link first and second nodes
    head->data = 7;
    head->next = second;

    //  Link second and third nodes
    second->data = 11;
    second->next = third;

    //  Terminate the list at the third node
    third->data = 22;
    third->next = NULL;

    LinkedlistTravers(head);
    printf("\n");
    head = DeletionatValue(head,11);
    LinkedlistTravers(head);
    return 0;
}