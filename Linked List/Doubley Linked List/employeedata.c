#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Node
{
    char SSN[20];
    char Name[20];
    char Dept[20];
    char Designation[20];
    int sal;
    long phno;
    struct Node *next;
    struct Node *prev;
};
struct Node *CreateNode(char SSN[20], char Name[20], char Dept[20], char Designation[20], int sal, long phno)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    strcpy(ptr->SSN, SSN);
    strcpy(ptr->Name, Name);
    strcpy(ptr->Dept, Dept);
    strcpy(ptr->Designation, Designation);
    ptr->sal = sal;
    ptr->phno = phno;
    ptr->next = NULL;
    ptr->prev = NULL;

    return ptr;
}
struct Node *InsertAtEnd(struct Node *head, char SSN[20], char Name[20], char Dept[20], char Designation[20], int sal, long phno)
{
    struct Node *ptr = CreateNode(SSN, Name, Dept, Designation, sal, phno);
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
        ptr->prev = p;
    }
    return head;
}
struct Node *InsertionatFirst(struct Node *head, char SSN[20], char Name[20], char Dept[20], char Designation[20], int sal, long phno)
{
    struct Node *ptr = CreateNode(SSN, Name, Dept, Designation, sal, phno);

    if (head == NULL)
    {
        return ptr;
    }

    ptr->next = head;
    head->prev = ptr;

    return ptr;
}
struct Node *InsertionAtIndex(struct Node *head, int value, int Index)
{
    if (Index == 0)
    {
        head = InsertionatFirst(head, value);
    }
    struct Node *ptr = CreateNode(value);
    struct Node *p = head;
    int i = 0;
    while (i <= Index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    ptr->prev = p;

    return head;
}
struct Node *DeletionAtFirst(struct Node *head)
{
    if (head == NULL)
    {
        return 0;
    }

    struct Node *ptr = head;

    head = head->next;
    head->prev = NULL;
    free(ptr);

    return head;
}
struct Node *DeletionatEnd(struct Node *head)
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
int LinkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;
    int i = 0;

    if (head == NULL)
    {
        printf("List is empty!\n");
        return i;
    }

    printf("Employee List:\n");
    while (ptr != NULL)
    {
        printf("SSN: %s, Name: %s, Dept: %s, Designation: %s, Salary: %d, Phone: %ld\n",
               ptr->SSN, ptr->Name, ptr->Dept, ptr->Designation, ptr->sal, ptr->phno);
        ptr = ptr->next;
        i++;
    }
    return i;
}
int main()
{
    struct Node *head = NULL;
    char SSN[20];
    char Name[20];
    char Dept[20];
    char Designation[20];
    int sal;
    long phno;

    int n;
    printf("Enter the no of nodes you want in your list:\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the details for Node %d:\n", i + 1);
        printf("SSN: ");
        scanf("%s", SSN); // No need for & since SSN is a char array
        printf("Name: ");
        scanf("%s", Name); // No need for &
        printf("Dept: ");
        scanf("%s", Dept); // No need for &
        printf("Designation: ");
        scanf("%s", Designation); // No need for &
        printf("Salary: ");
        scanf("%d", &sal);
        printf("Phone: ");
        scanf("%ld", &phno);

        head = InsertAtEnd(head, SSN, Name, Dept, Designation, sal, phno);
    }

    int m = LinkedListTraversal(head);
    printf("The total number of employees are: %d\n", m);

    // Queue Demonstration
    // Insertion at Front
    head = InsertionatFirst(head, "3", "3", "3", "3", 3, 3); // just for example

    // Deletion at end
    head = DeletionatEnd(head);

    m = LinkedListTraversal(head);

    return 0;
}