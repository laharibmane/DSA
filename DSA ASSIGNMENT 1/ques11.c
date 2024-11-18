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
void linkedlisttraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
struct Node *add(struct Node *first, struct Node *second)
{
    struct Node *result = NULL;
    struct Node *prev = NULL;
    struct Node *temp = NULL;
    int sum, carry = 0;

    while (first != NULL || second != NULL)
    {
        sum = carry + (first ? first->data : 0) + (second ? second->data : 0);

        carry = sum / 10;
        sum = sum % 10;

        temp = createNode(sum);

        if (result == NULL)
        {
            result = temp;
        }
        else
        {
            prev->next = temp;
        }
        prev = temp;

        if (first)
        {
            first = first->next;
        }
        if (second)
        {
            second = second->next;
        }
    }

    if (carry > 0)
    {
        temp->next = createNode(carry);
    }
    return result;
}
int main()
{

    struct Node *first = NULL;
    int n, value;
    printf("Enter the number of nodes you want in your first linked list: \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the value for Node %d: ", i);
        scanf("%d", &value);
        first = insertAtEnd(first, value);
    }
    struct Node *second = NULL;
    printf("Enter the number of nodes you want in your first linked list: \n");
    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; i++)
    {
        printf("Enter the value for Node %d: ", i);
        scanf("%d", &value);
        second = insertAtEnd(second, value);
    }

    struct Node *result = NULL;
    result = add(first, second);

    printf("First List:\n");
    linkedlisttraversal(first);

    printf("Second list:\n");
    linkedlisttraversal(second);

    printf("Result:\n");
    linkedlisttraversal(result);
    return 0;
}