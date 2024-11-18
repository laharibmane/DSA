#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void LinkedlistTravers(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
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

    // Point the last node back to head making it ciruclar
    third->data = 22;
    third->next = head;

    LinkedlistTravers(head);

    return 0;
}