// Implement an AVL-Tree program with functions for insertion and deletion while maintaining the AVL-Tree's height balance property. The elements to be inserted in the AVL-Tree should be taken as input from the user. Delete the user-given elements from the AVL-Tree.
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int height(struct Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}

int maximum(int a, int b)
{
    return (a < b) ? a : b;
}

struct Node *newNode(int key)
{
    struct Node *tempNode = (struct Node *)malloc(sizeof(struct Node));
    tempNode->key = key;
    tempNode->left = NULL;
    tempNode->right = NULL;
    tempNode->height = 1;
    return (tempNode);
}

struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *z = x->right;

    x->right = y;
    y->left = z;

    y->height = maximum(height(y->left), height(y->right)) + 1;
    z->height = maximum(height(z->left), height(z->right)) + 1;

    return x;
}

struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->left;
    struct Node *z = x->right;

    y->left = x;
    x->right = z;

    x->height = maximum(height(x->left), height(x->right)) + 1;
    y->height = maximum(height(y->left), height(y->right)) + 1;

    return y;
}

int getBal(struct Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return (height(node->left) - height(node->right));
}

struct Node *insert(struct Node *n, int key)
{
    if (n == NULL)
    {
        return (newNode(key));
    }

    if (key < n->key)
    {
        n->left = insert(n->left, key);
    }
    else if (key > n->key)
    {
        n->right = insert(n->right, key);
    }
    else
    {
        return n;
    }

    n->height = 1 + maximum(height(n->left), height(n->right));

    int bal = getBal(n);
    if (bal > 1 && key < n->left->key)
    {
        return rightRotate(n);
    }
    if (bal < -1 && key > n->right->key)
    {
        return leftRotate(n);
    }
    if (bal > 1 && key > n->left->key)
    {
        n->left = leftRotate(n->left);
        return rightRotate(n);
    }
    if (bal < -1 && key < n->right->key)
    {
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }

    return n;
}

struct Node *minValNode(struct Node *n)
{
    struct Node *current = n;

    while (current->left != NULL)
    {
        current = current->left;
    }

    return current;
}

struct Node *delNode(struct Node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (key < root->key)
    {
        root->left = delNode(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = delNode(root->right, key);
    }
    else
    {
        if ((root->left == NULL) || (root->right == NULL))
        {
            struct Node *temp = root->left ? root->left : root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            {
                *root = *temp;
            }
            free(temp);
        }
        else
        {
            struct Node *temp = minValNode(root->right);

            root->key = temp->key;

            root->right = delNode(root->right, temp->key);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + maximum(height(root->left),
                               height(root->right));

    int bal = getBal(root);
    if (bal > 1 && getBal(root->left) >= 0)
    {
        return rightRotate(root);
    }
    if (bal > 1 && getBal(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (bal < -1 && getBal(root->right) <= 0)
    {
        return leftRotate(root);
    }
    if (bal < -1 && getBal(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void main()
{
    struct Node *root = NULL;
    int ch, elem;
    do
    {
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter element to insert: ");
            scanf("%d", &elem);
            root = insert(root, elem);
            break;
        case 2:
            printf("Enter element to delete: ");
            scanf("%d", &elem);
            root = delNode(root, elem);
            break;
        case 3:
            printf("Pre-order tree traversal: ");
            preOrder(root);
            printf("\n");
            break;
        case 4:
            break;
        default:
            printf("Enter valid option");
        }
    } while (ch != 4);
}
