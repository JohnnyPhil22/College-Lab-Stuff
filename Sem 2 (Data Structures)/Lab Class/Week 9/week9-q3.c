// Implement B+ Tree. Perform insertion and deletion in B+ Tree by utilizing user-given inputs. Also, take the order of the B+ Tree as input from the user.
#include <stdio.h>
#include <stdlib.h>
struct BplusTree
{
    int *d;
    struct BplusTree **child_ptr;
    int l;
    int n;
};
struct BplusTree *root = NULL, *np = NULL, *x = NULL;
struct BplusTree *init()
{
    int i;
    np = (struct BplusTree *)malloc(sizeof(struct BplusTree));
    np->d = (int *)malloc(6 * sizeof(int));
    np->child_ptr = (struct BplusTree **)malloc(7 * sizeof(struct BplusTree *));
    np->l = 1;
    np->n = 0;
    for (i = 0; i < 7; i++)
    {
        np->child_ptr[i] = NULL;
    }
    return np;
}
void traverse(struct BplusTree *p)
{
    int i;
    for (i = 0; i < p->n; i++)
    {
        if (p->l == 0)
        {
            traverse(p->child_ptr[i]);
        }
        printf("%d ", p->d[i]);
    }
    if (p->l == 0)
    {
        traverse(p->child_ptr[i]);
    }
    printf("\n");
}

void sort(int *p, int n)
{
    int i, j, t;
    for (i = 0; i < n; i++)
    {
        for (j = i; j <= n; j++)
        {
            if (p[i] > p[j])
            {
                t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
        }
    }
}

int split_child(struct BplusTree *x, int i)
{
    int j, mid;
    struct BplusTree *np1, *np3, *y;
    np3 = init();
    np3->l = 1;
    if (i == -1)
    {
        mid = x->d[2];
        x->d[2] = 0;
        x->n--;
        np1 = init();
        np1->l = 0;
        x->l = 1;
        for (j = 3; j < 6; j++)
        {
            np3->d[j - 3] = x->d[j];
            np3->child_ptr[j - 3] = x->child_ptr[j];
            np3->n++;
            x->d[j] = 0;
            x->n--;
        }
        for (j = 0; j < 6; j++)
        {
            x->child_ptr[j] = NULL;
        }
        np1->d[0] = mid;
        np1->child_ptr[np1->n] = x;
        np1->child_ptr[np1->n + 1] = np3;
        np1->n++;
        root = np1;
    }
    else
    {
        y = x->child_ptr[i];
        mid = y->d[2];
        y->d[2] = 0;
        y->n--;
        for (j = 3; j < 6; j++)
        {
            np3->d[j - 3] = y->d[j];
            np3->n++;
            y->d[j] = 0;
            y->n--;
        }
        x->child_ptr[i + 1] = y;
        x->child_ptr[i + 1] = np3;
    }
    return mid;
}

void insert(int a)
{
    int i, t;
    x = root;
    if (x == NULL)
    {
        root = init();
        x = root;
    }
    else
    {
        if (x->l == 1 && x->n == 6)
        {
            t = split_child(x, -1);
            x = root;
            for (i = 0; i < x->n; i++)
            {
                if (a > x->d[i] && a < x->d[i + 1])
                {
                    i++;
                    break;
                }
                else if (a < x->d[0])
                {
                    break;
                }
                else
                {
                    continue;
                }
            }
            x = x->child_ptr[i];
        }
        else
        {
            while (x->l == 0)
            {
                for (i = 0; i < x->n; i++)
                {
                    if (a > x->d[i] && a < x->d[i + 1])
                    {
                        i++;
                        break;
                    }
                    else if (a < x->d[0])
                    {
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
                if (x->child_ptr[i]->n == 6)
                {
                    t = split_child(x, i);
                    x->d[x->n] = t;
                    x->n++;
                    continue;
                }
                else
                {
                    x = x->child_ptr[i];
                }
            }
        }
    }
    x->d[x->n] = a;
    sort(x->d, x->n);
    x->n++;
}

void delete_key_from_node(struct BplusTree *node, int key)
{
    int i = 0;
    while (i < node->n && node->d[i] != key)
    {
        i++;
    }
    if (i < node->n)
    {
        for (int j = i; j < node->n - 1; j++)
        {
            node->d[j] = node->d[j + 1];
        }
        node->n--;
    }
}

void borrow_key(struct BplusTree *node, int idx)
{
    if (idx != 0 && node->child_ptr[idx - 1]->n > 2)
    {
        struct BplusTree *left_sibling = node->child_ptr[idx - 1];
        struct BplusTree *child = node->child_ptr[idx];

        for (int i = child->n; i > 0; i--)
        {
            child->d[i] = child->d[i - 1];
        }
        child->d[0] = node->d[idx - 1];
        node->d[idx - 1] = left_sibling->d[left_sibling->n - 1];

        if (child->l == 0)
        {
            for (int i = child->n + 1; i > 0; i--)
            {
                child->child_ptr[i] = child->child_ptr[i - 1];
            }
            child->child_ptr[0] = left_sibling->child_ptr[left_sibling->n];
        }

        child->n++;
        left_sibling->n--;
    }
    else if (idx != node->n && node->child_ptr[idx + 1]->n > 2)
    {
        struct BplusTree *right_sibling = node->child_ptr[idx + 1];
        struct BplusTree *child = node->child_ptr[idx];

        child->d[child->n] = node->d[idx];
        node->d[idx] = right_sibling->d[0];

        if (child->l == 0)
        {
            child->child_ptr[child->n + 1] = right_sibling->child_ptr[0];

            for (int i = 0; i < right_sibling->n - 1; i++)
            {
                right_sibling->d[i] = right_sibling->d[i + 1];
                right_sibling->child_ptr[i] = right_sibling->child_ptr[i + 1];
            }
            right_sibling->child_ptr[right_sibling->n - 1] = right_sibling->child_ptr[right_sibling->n];
        }

        child->n++;
        right_sibling->n--;
    }
    else
    {
        if (idx != node->n)
        {
            struct BplusTree *child = node->child_ptr[idx];
            struct BplusTree *right_sibling = node->child_ptr[idx + 1];

            child->d[2] = node->d[idx];
            child->d[3] = right_sibling->d[0];
            child->d[4] = right_sibling->d[1];

            if (child->l == 0)
            {
                child->child_ptr[3] = right_sibling->child_ptr[0];
                child->child_ptr[4] = right_sibling->child_ptr[1];
                child->child_ptr[5] = right_sibling->child_ptr[2];
            }

            for (int i = idx; i < node->n - 1; i++)
            {
                node->d[i] = node->d[i + 1];
                node->child_ptr[i + 1] = node->child_ptr[i + 2];
            }
        }
        else
        {
            struct BplusTree *left_sibling = node->child_ptr[idx - 1];
            struct BplusTree *child = node->child_ptr[idx - 1];

            left_sibling->d[2] = node->d[idx - 1];
            left_sibling->d[3] = child->d[0];
            left_sibling->d[4] = child->d[1];

            if (left_sibling->l == 0)
            {
                left_sibling->child_ptr[3] = child->child_ptr[0];
                left_sibling->child_ptr[4] = child->child_ptr[1];
                left_sibling->child_ptr[5] = child->child_ptr[2];
            }

            for (int i = idx - 1; i < node->n - 1; i++)
            {
                node->d[i] = node->d[i + 1];
                node->child_ptr[i + 1] = node->child_ptr[i + 2];
            }
        }
        node->n--;
        free(node->child_ptr[node->n]);
        node->child_ptr[node->n] = NULL;
    }
}

void merge_nodes(struct BplusTree *parent, int idx)
{
    struct BplusTree *left_child = parent->child_ptr[idx];
    struct BplusTree *right_child = parent->child_ptr[idx + 1];

    left_child->d[left_child->n] = parent->d[idx];
    left_child->n++;

    for (int i = 0; i < right_child->n; i++)
    {
        left_child->d[left_child->n] = right_child->d[i];
        left_child->child_ptr[left_child->n] = right_child->child_ptr[i];
        left_child->n++;
    }

    left_child->child_ptr[left_child->n] = right_child->child_ptr[right_child->n];

    free(right_child);
    for (int i = idx; i < parent->n - 1; i++)
    {
        parent->d[i] = parent->d[i + 1];
        parent->child_ptr[i + 1] = parent->child_ptr[i + 2];
    }
    parent->n--;

    if (parent->n == 0)
    {
        if (parent == root)
        {
            root = left_child;
        }
        free(parent);
    }
}

void delete_key(struct BplusTree *node, int key)
{
    if (node == NULL)
        return;
    delete_key_from_node(node, key);

    if (node == root && node->n == 0)
    {
        if (node->l == 0)
        {
            root = node->child_ptr[0];
        }
        else
        {
            root = NULL;
        }
        free(node);
        return;
    }
    if (node->n < 2)
    {
        int idx;
        struct BplusTree *parent = NULL;
        struct BplusTree *temp = root;
        while (temp != NULL && temp != node)
        {
            parent = temp;
            int i = 0;
            while (i < temp->n && key > temp->d[i])
            {
                i++;
            }
            if (i < temp->n && key == temp->d[i])
            {
                idx = i;
                break;
            }
            temp = temp->child_ptr[i];
        }
        if (parent == NULL)
        {
            if (node->n == 0)
            {
                root = node->child_ptr[0];
                free(node);
                return;
            }
        }
        if (idx != 0 && parent->child_ptr[idx - 1]->n > 2)
        {
            borrow_key(parent, idx);
        }
        else if (idx != parent->n && parent->child_ptr[idx + 1]->n > 2)
        {
            borrow_key(parent, idx + 1);
        }
        else
        {
            if (idx != parent->n)
            {
                merge_nodes(parent, idx);
            }
            else
            {
                merge_nodes(parent, idx - 1);
            }
        }
    }
}

void delete_recursive(struct BplusTree *node, int key)
{
    if (node == NULL)
        return;
    int i = 0;
    while (i < node->n && key > node->d[i])
    {
        i++;
    }
    if (node->l == 1)
    {
        if (i < node->n && node->d[i] == key)
        {
            delete_key(node, key);
            return;
        }
        return;
    }
    delete_recursive(node->child_ptr[i], key);
}

void del(int key)
{
    if (root == NULL)
    {
        printf("B+ Tree is empty\n");
        return;
    }
    delete_recursive(root, key);
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
            del(elem);
            break;
        case 3:
            printf("B+ Tree: ");
            traverse(root);
            break;
        case 4:
            break;
        default:
            printf("Enter valid option");
        }
    } while (ch != 4);
}