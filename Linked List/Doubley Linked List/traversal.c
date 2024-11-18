#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
void ForwardLinkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
void reverse(struct Node *fourth)
{
    struct Node *ptr = fourth;
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->prev;
    }
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 33;
    head->next = second;
    head->prev = NULL;

    second->data = 45;
    second->next = third;
    second->prev = head;

    third->data = 56;
    third->next = fourth;
    third->prev = second;

    fourth->data = 76;
    fourth->next = NULL;
    fourth->prev = third;

    printf("Linked List in order: \n");
    ForwardLinkedListTraversal(head);
    printf("\n");
    printf("Linked List in reversed order: \n");
    reverse(fourth);
    return 0;
}