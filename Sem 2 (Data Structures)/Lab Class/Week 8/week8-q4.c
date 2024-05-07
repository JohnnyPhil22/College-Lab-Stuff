// Implement a Binary Search Tree program that can perform the following operations:
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a Binary Search Tree by taking the integer value of node elements as input from the user.
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

// Print height of the Binary Search Tree.
int height(struct Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    int lheight = height(root->left), rheight = height(root->right);
    return (lheight > rheight ? lheight : rheight) + 1;
}

// Count the number of elements present at the last level of the Binary Search Tree. Print the counted value.
int countLastLevel(struct Node *root, int level, int currentLevel)
{
    if (root == NULL)
    {
        return 0;
    }
    if (currentLevel == level)
    {
        return 1;
    }
    return countLastLevel(root->left, level, currentLevel + 1) + countLastLevel(root->right, level, currentLevel + 1);
}

// Find out the level of the node having maximum value in the Binary Search Tree.
int findMaxLevel(struct Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    int maxLevel = 0;
    struct Node *current = root;
    while (current->right != NULL)
    {
        current = current->right;
        maxLevel++;
    }
    return maxLevel;
}

// Find out the level of the node having minimum value in the Binary Search Tree.
int findMinLevel(struct Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    int minLevel = 0;
    struct Node *current = root;
    while (current->left != NULL)
    {
        current = current->left;
        minLevel++;
    }
    return minLevel;
}

int main()
{
    struct Node *root = NULL;
    int ch, data;

    do
    {
        printf("1. Insert\n2. Print height\n3. Count number of elements at last level\n4. Level of node with maximum value\n5. Level of node with minimum value\n6. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            printf("Height of the tree: %d\n", height(root));
            break;
        case 3:
        {
            int lastLevel = height(root);
            printf("Number of elements at the last level: %d\n", countLastLevel(root, lastLevel, 0));
            break;
        }
        case 4:
            printf("Level of node with maximum value: %d\n", findMaxLevel(root));
            break;
        case 5:
            printf("Level of node with minimum value: %d\n", findMinLevel(root));
            break;
        case 6:
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (ch != 6);
}