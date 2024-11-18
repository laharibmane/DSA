#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height; // balance factor mod
};
int getHeight(struct Node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    else
        return n->height;
}

struct Node *createNode(int key)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->key = key;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;
    return n;
}
int max(int a, int b)
{
    return a > b ? a : b;
}
int getBalanceFactor(struct Node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    else
        return getHeight(n->left) - getHeight(n->right);
}

struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return x;
}

struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return y;
}

struct Node *insert(struct Node *node, int key)
{
    if (node == NULL)
    {
        return createNode(key);
    }
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    node->height = max(getHeight(node->right), getHeight(node->left)) + 1;
    int bf = getBalanceFactor(node);

    // Left Left case
    if (bf > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }
    // right right case
    if (bf < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }
    // left right case
    if (bf > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // right left case
    if (bf < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
void preordertraversal(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preordertraversal(root->left);
        preordertraversal(root->right);
    }
}
int main()
{
    struct Node *root = NULL;
    root = insert(root,1);
    root = insert(root,2);
    root = insert(root,4);
    root = insert(root,5);
    root = insert(root,6);
    root = insert(root,3);

    preordertraversal(root);
    return 0;
}