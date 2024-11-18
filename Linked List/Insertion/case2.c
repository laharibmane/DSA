#include <stdio.h>
#include <stdlib.h>
// case 2 - Insertion in between
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
struct Node * insertatFirst(struct Node * head,int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;

}
struct Node *insertatIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    if (index == 0)
    {
       return insertatFirst(head,data);
    }
    
    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
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
    head = insertatIndex(head,56,1);
    LinkedlistTravers(head);
    return 0;
}