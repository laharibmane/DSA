#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    char ssn[50];
    char name[50];
    char dept[50];
    char designation[50];
    float salary;
    long phone;
    struct Node *next;
};
struct Node *CreateNode(char ssn[50], char name[50], char dept[50], char designation[50], float salary, long phone)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    strcpy(ptr->ssn, ssn);
    strcpy(ptr->name, name);
    strcpy(ptr->dept, dept);
    strcpy(ptr->designation, designation);
    ptr->salary = salary;
    ptr->phone = phone;
    ptr->next = NULL;

    return ptr;
};
struct Node *InsertionAtEnd(struct Node *head, char ssn[50], char name[50], char dept[50], char designation[50], float salary, long phone)
{

    struct Node *ptr = CreateNode(ssn, name, dept, designation, salary, phone);

    if (head == NULL)
    {
        ptr->next = ptr;
        return ptr;
    }
    

    struct Node *p = head;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;

    return head;
}
struct Node *InsertionAtHead(struct Node *head, char ssn[50], char name[50], char dept[50], char designation[50], float salary, long phone)
{
    struct Node *ptr = CreateNode(ssn, name, dept, designation, salary, phone);

    struct Node *p = head;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;

    return head;
}
struct Node *DeletionAtEnd(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
        ptr = ptr->next;
    }

    ptr->next = p->next;
    free(p);
    return head;
}
struct Node *DeletionAtHead(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *p = head->next;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr->next;
    head = head->next;
    free(ptr);

    return head;
}
int CiruclarLinkedListTraverse(struct Node *head){
    int i = 0;
    struct Node *ptr = head;
    do
    {
        printf("SSN: %s, Name: %s, Dept: %s, Designation: %s, Salary: %f, Phone: %ld\n",
               ptr->ssn, ptr->name, ptr->dept, ptr->designation, ptr->salary, ptr->phone);
               i++;
               ptr = ptr->next;
    } while (ptr!=head);
    return i;
}
int main()
{
    struct Node *head = NULL;
    char SSN[50];
    char Name[50];
    char Dept[50];
    char Designation[50];
    float sal;
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
        scanf("%f", &sal);
        printf("Phone: ");
        scanf("%ld", &phno);

        head = InsertionAtEnd(head, SSN, Name, Dept, Designation, sal, phno);
    }

    int m = CiruclarLinkedListTraverse(head);
    printf("No of Nodes in this Current circular linked list:\n");
    printf("%d\n",m);

    head = InsertionAtHead(head,"3","3","3","3",3,3);
    head = DeletionAtEnd(head);
    m = CiruclarLinkedListTraverse(head);

    return 0;
}