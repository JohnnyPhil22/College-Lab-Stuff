// Implement a Binary Search Tree program that can perform the following operations:
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a Binary Search Tree by taking integer node values as input from the user.
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Unable to allocate memory");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
    }
    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

// Delete the user-given elements from the Binary Search Tree.
struct Node *findMinValueNode(struct Node *node)
{
    struct Node *current = node;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

struct Node *deleteNode(struct Node *root, int data)
{
    if (root == NULL)
        return root;

    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        struct Node *temp = findMinValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Display the in-order traversal sequence of the Binary Search Tree.
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Print pre-order traversal sequence of the Binary Search Tree.
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Display post-order traversal sequence of the Binary Search Tree.
void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Search the user-given element in the Binary Search Tree. Check whether the element to be searched is present in the Binary Search Tree or not.
struct Node *search(struct Node *root, int data)
{
    if (root == NULL || root->data == data)
    {
        return root;
    }

    if (data < root->data)
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
}

int main()
{
    struct Node *root = NULL;
    int ch, data;

    do
    {
        printf("1. Insert\n2. Delete\n3. In-order traversal\n4. Pre-order traversal\n5. Post-order traversal\n6. Search element\n7. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            printf("Enter data to delete: ");
            scanf("%d", &data);
            root = deleteNode(root, data);
            break;
        case 3:
            printf("In-order traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 4:
            printf("Pre-order traversal: ");
            preorder(root);
            printf("\n");
            break;
        case 5:
            printf("Post-order traversal: ");
            postorder(root);
            printf("\n");
            break;
        case 6:
            printf("Enter element to search: ");
            scanf("%d", &data);
            if (search(root, data) != NULL)
            {
                printf("%d present in binary search tree\n", data);
            }
            else
            {
                printf("%d not present in binary search tree\n", data);
            }
            break;
        case 7:
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (ch != 7);
}