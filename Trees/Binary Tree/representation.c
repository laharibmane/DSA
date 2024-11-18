#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node)); // create Node pointer and allocating memory in the heap
    n->data = data;                                              // Setting the data
    n->left = NULL;                                              // Left Node child to NULL
    n->right = NULL;                                             // Right Node child to NULL
    return n;                                                    // returning the created Node
}
int main()
{
    // Root Node
    // struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    // p->data = 7;
    // p->right = NULL;
    // p->left = NULL;

    // // 2nd Node
    // struct Node *p1 = (struct Node *)malloc(sizeof(struct Node));
    // p1->data = 2;
    // p1->right = NULL;
    // p1->left = NULL;

    // // 3rd Node
    // struct Node *p2 = (struct Node *)malloc(sizeof(struct Node));
    // p2->data = 4;
    // p2->right = NULL;
    // p2->left = NULL;

    struct Node *p = createNode(12);
    struct Node *p1 = createNode(5);
    struct Node *p2 = createNode(6);

    // Linking Root Node with Left And Right children
    p->left = p1;
    p->right = p2;
    return 0;
}