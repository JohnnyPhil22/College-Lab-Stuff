// Implement B-Tree. Perform insertion and deletion operations by taking inputs from the user. Also, take the order of the B-Tree as input from the user.
#include <stdio.h>
#include <stdlib.h>

#define MAX 5
#define MIN 2

struct Node
{
    int val[MAX + 1], count;
    struct Node *link[MAX + 1];
} *root;

struct Node *createNode(int val, struct Node *child)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->val[1] = val;
    newNode->count = 1;
    newNode->link[0] = root;
    newNode->link[1] = child;
    return newNode;
}

void insNode(int val, int pos, struct Node *node, struct Node *child)
{
    int j = node->count;
    while (j > pos)
    {
        node->val[j + 1] = node->val[j];
        node->link[j + 1] = node->link[j];
        j--;
    }
    node->val[j + 1] = val;
    node->link[j + 1] = child;
    node->count++;
}

void splitNode(int val, int *pval, int pos, struct Node *node, struct Node *child, struct Node **newNode)
{
    int median, j;
    if (pos > MIN)
    {
        median = MIN + 1;
    }
    else
    {
        median = MIN;
    }

    *newNode = (struct Node *)malloc(sizeof(struct Node));
    j = median + 1;
    while (j <= MAX)
    {
        (*newNode)->val[j - median] = node->val[j];
        (*newNode)->link[j - median] = node->link[j];
        j++;
    }
    node->count = median;
    (*newNode)->count = MAX - median;

    if (pos <= MIN)
    {
        insNode(val, pos, node, child);
    }
    else
    {
        insNode(val, pos - median, *newNode, child);
    }
    *pval = node->val[node->count];
    (*newNode)->link[0] = node->link[node->count];
    node->count--;
}

int setVal(int val, int *pval, struct Node *node, struct Node **child)
{
    int pos;
    if (!node)
    {
        *pval = val;
        *child = NULL;
        return 1;
    }

    if (val < node->val[1])
    {
        pos = 0;
    }
    else
    {
        for (pos = node->count; (val < node->val[pos] && pos > 1); pos--)
            ;
        if (val == node->val[pos])
        {
            printf("No duplicates allowed\n");
            return 0;
        }
    }
    if (setVal(val, pval, node->link[pos], child))
    {
        if (node->count < MAX)
        {
            insNode(*pval, pos, node, *child);
        }
        else
        {
            splitNode(*pval, pval, pos, node, *child, child);
            return 1;
        }
    }
    return 0;
}

void insert(int val)
{
    int flag, i;
    struct Node *child;

    flag = setVal(val, &i, root, &child);
    if (flag)
        root = createNode(i, child);
}

void copySuccessor(struct Node *myNode, int pos)
{
    struct Node *dummy;
    dummy = myNode->link[pos];

    for (; dummy->link[0] != NULL;)
        dummy = dummy->link[0];
    myNode->val[pos] = dummy->val[1];
}

void removeVal(struct Node *myNode, int pos)
{
    int i = pos + 1;
    while (i <= myNode->count)
    {
        myNode->val[i - 1] = myNode->val[i];
        myNode->link[i - 1] = myNode->link[i];
        i++;
    }
    myNode->count--;
}

void rightShift(struct Node *myNode, int pos)
{
    struct Node *x = myNode->link[pos];
    int j = x->count;

    while (j > 0)
    {
        x->val[j + 1] = x->val[j];
        x->link[j + 1] = x->link[j];
    }
    x->val[1] = myNode->val[pos];
    x->link[1] = x->link[0];
    x->count++;

    x = myNode->link[pos - 1];
    myNode->val[pos] = x->val[x->count];
    myNode->link[pos] = x->link[x->count];
    x->count--;
    return;
}

void leftShift(struct Node *myNode, int pos)
{
    int j = 1;
    struct Node *x = myNode->link[pos - 1];

    x->count++;
    x->val[x->count] = myNode->val[pos];
    x->link[x->count] = myNode->link[pos]->link[0];

    x = myNode->link[pos];
    myNode->val[pos] = x->val[1];
    x->link[0] = x->link[1];
    x->count--;

    while (j <= x->count)
    {
        x->val[j] = x->val[j + 1];
        x->link[j] = x->link[j + 1];
        j++;
    }
    return;
}

void mergeNodes(struct Node *myNode, int pos)
{
    int j = 1;
    struct Node *x1 = myNode->link[pos], *x2 = myNode->link[pos - 1];

    x2->count++;
    x2->val[x2->count] = myNode->val[pos];
    x2->link[x2->count] = myNode->link[0];

    while (j <= x1->count)
    {
        x2->count++;
        x2->val[x2->count] = x1->val[j];
        x2->link[x2->count] = x1->link[j];
        j++;
    }

    j = pos;
    while (j < myNode->count)
    {
        myNode->val[j] = myNode->val[j + 1];
        myNode->link[j] = myNode->link[j + 1];
        j++;
    }
    myNode->count--;
    free(x1);
}

void adjustNode(struct Node *myNode, int pos)
{
    if (!pos)
    {
        if (myNode->link[1]->count > MIN)
        {
            leftShift(myNode, 1);
        }
        else
        {
            mergeNodes(myNode, 1);
        }
    }
    else
    {
        if (myNode->count != pos)
        {
            if (myNode->link[pos - 1]->count > MIN)
            {
                rightShift(myNode, pos);
            }
            else
            {
                if (myNode->link[pos + 1]->count > MIN)
                {
                    leftShift(myNode, pos + 1);
                }
                else
                {
                    mergeNodes(myNode, pos);
                }
            }
        }
        else
        {
            if (myNode->link[pos - 1]->count > MIN)
                rightShift(myNode, pos);
            else
                mergeNodes(myNode, pos);
        }
    }
}

int delVal(int item, struct Node *myNode)
{
    int pos, flag = 0;
    if (myNode)
    {
        if (item < myNode->val[1])
        {
            pos = 0;
            flag = 0;
        }
        else
        {
            for (pos = myNode->count; (item < myNode->val[pos] && pos > 1); pos--)
                ;
            if (item == myNode->val[pos])
            {
                flag = 1;
            }
            else
            {
                flag = 0;
            }
        }
        if (flag)
        {
            if (myNode->link[pos - 1])
            {
                copySuccessor(myNode, pos);
                flag = delVal(myNode->val[pos], myNode->link[pos]);
                if (flag == 0)
                {
                    printf("Data not present in B-Tree\n");
                }
            }
            else
            {
                removeVal(myNode, pos);
            }
        }
        else
        {
            flag = delVal(item, myNode->link[pos]);
        }
        if (myNode->link[pos])
        {
            if (myNode->link[pos]->count < MIN)
            {
                adjustNode(myNode, pos);
            }
        }
    }
    return flag;
}

void delete(int item, struct Node *myNode)
{
    struct Node *tmp;
    if (!delVal(item, myNode))
    {
        printf("Not present\n");
        return;
    }
    else
    {
        if (myNode->count == 0)
        {
            tmp = myNode;
            myNode = myNode->link[0];
            free(tmp);
        }
    }
    root = myNode;
    return;
}

void traversal(struct Node *myNode)
{
    int i;
    if (myNode)
    {
        for (i = 0; i < myNode->count; i++)
        {
            traversal(myNode->link[i]);
            printf("%d ", myNode->val[i + 1]);
        }
        traversal(myNode->link[i]);
    }
}

void main()
{
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
            insert(elem);
            break;
        case 2:
            printf("Enter element to delete: ");
            scanf("%d", &elem);
            delete (elem, root);
            break;
        case 3:
            printf("B-Tree: ");
            traversal(root);
            printf("\n");
            break;
        case 4:
            break;
        default:
            printf("Enter valid option");
        }
    } while (ch != 4);
}