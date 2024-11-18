#include <stdio.h>
#include <stdlib.h>
// case 1 - Deletion of First element in the list
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

struct Node *DeletionatFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
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

    LinkedlistTravers(head); // before removal
    head = DeletionatFirst(head);
    printf("\n");
    LinkedlistTravers(head); // after removal

    return 0;
}