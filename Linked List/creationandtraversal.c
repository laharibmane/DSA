#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void LinkedlistTravers(struct Node *ptr)
{
    while (ptr!=NULL)
    {
        printf("Element: %d\n",ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

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
    third->next = fourth;

    fourth->data = 44;
    fourth->next = NULL;    

    LinkedlistTravers(head);

    return 0;
}