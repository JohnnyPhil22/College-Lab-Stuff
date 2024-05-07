// Perform in-order traversal of a Height Balanced Binary Search Tree to print the elements in sorted order. Elements to be inserted in the Height Balanced Binary Search Tree should be taken as input from the user.
#include <stdio.h>
#include <stdlib.h>
#define bool int

struct node
{
    int item;
    struct node *left;
    struct node *right;
};

struct node *createNode(int item)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed");
        exit(1);
    }
    newNode->item = item;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct node *constructBST(int arr[], int start, int end)
{
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    struct node *root = createNode(arr[mid]);

    root->left = constructBST(arr, start, mid - 1);
    root->right = constructBST(arr, mid + 1, end);

    return root;
}

void inOrder(struct node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->item);
    inOrder(root->right);
}

void main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    struct node *root = constructBST(arr, 0, n - 1);

    printf("Balanced BST: ");
    inOrder(root);
    printf("\n");

    free(arr);
}