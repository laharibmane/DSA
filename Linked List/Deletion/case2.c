#include <stdio.h>
#include <stdlib.h>
// case 2 - Deletion in between at a given index from the linked list can only start from index 1
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
struct Node *DeletionAtFirst(struct Node *head){
    struct Node *ptr = head;
    head = head->next;
    free(ptr);

    return head;
}
struct Node *DeletionainBetween(struct Node *head, int Index)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    if (Index == 0)
    {
        return DeletionAtFirst(head);
    }
    
    while (i!=Index-1)
    {
        p = p->next;
        i++;
    }
    ptr = p->next;
    p->next = ptr->next;
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

    LinkedlistTravers(head);
    printf("\n");
    head = DeletionainBetween(head,1);
    LinkedlistTravers(head);
    return 0;
}