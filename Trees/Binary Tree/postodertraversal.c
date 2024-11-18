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
void postordertraversal(struct Node *root)
{
    if (root != NULL)
    {
        postordertraversal(root->left);
        postordertraversal(root->right);
        printf("%d ", root->data);
    }
}
int main()
{

    struct Node *p = createNode(12);
    struct Node *p1 = createNode(5);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(9);
    struct Node *p4 = createNode(4);

    // Linking Root Node with Left And Right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    postordertraversal(p);

    // Tree Looks like this:
    //  12
    //  /  \
    //  5   6
    // / \
    //9   4
    return 0;
}