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
void preordertraversal(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preordertraversal(root->left);
        preordertraversal(root->right);
    }
}
void inordertraversal(struct Node *root)
{
    if (root != NULL)
    {
        inordertraversal(root->left);
        printf("%d ", root->data);
        inordertraversal(root->right);
    }
}
int isBST(struct Node *root)
{
    static struct Node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}
struct Node *search(struct Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (key == root->data)
    {
        return root;
    }
    else if (key < root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}
struct Node *searchIterative(struct Node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}
void insert(struct Node *root,int key){
    struct Node *prev = NULL;
    while (root!=NULL)
    {
        prev = root;
        if (root->data == key)
        {
            printf("Duplicate Data Not allowed!\n");
            return ;
        }
        else if (root->data < key)
        {
            root = root->right;
        }
        else{
            root = root->left;
        }
    }
    struct Node *new = createNode(key);
    if (key < prev->data)
    {
        prev->left = new;
    }
    else prev->right = new;
    
}
int main()
{

    struct Node *p = createNode(12);
    struct Node *p1 = createNode(5);
    struct Node *p2 = createNode(13);
    struct Node *p3 = createNode(3);
    struct Node *p4 = createNode(7);

    // Linking Root Node with Left And Right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    printf("Post-Order Traversal: ");
    postordertraversal(p);
    printf("\n");

    printf("Pre-Order Traversal: ");
    preordertraversal(p);
    printf("\n");

    printf("In-Order Traversal: ");
    inordertraversal(p);
    printf("\n");

    if (isBST(p))
    {
        printf("It is a Binary Search Tree!\n");
    }
    else
    {
        printf("It is not a Binary Search Tree!\n");
    }
    struct Node *n = search(p, 3);
    if (n != NULL)
    {
        printf("Found through Recursion: %d\n", n->data);
    }
    else
    {
        printf("Not Found:");
    }

    struct Node *l = searchIterative(p, 3);
    if (l != NULL)
    {
        printf("Found through Iterative Approach: %d\n", l->data);
    }
    else
    {
        printf("Not Found:");
    }

    printf("After inserting an element: \n");
    insert(p,6);
    insert(p,6);
    inordertraversal(p);
    return 0;
}
