// Insert a node at user-given location within the Singly Linked List. Further, include a function which can delete a node from the Singly Linked List as per the user-given location.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtLocation(struct Node** head, int data, int position) {
    if (position < 1) {
        printf("Invalid position\n");
        return;
    }
    struct Node* newNode = createNode(data);
    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtLocation(struct Node** head, int position) {
    if (position < 1 || *head == NULL) {
        printf("Invalid position or empty list\n");
        return;
    }
    if (position == 1) {
        struct Node* temp = *head;
        *head = temp->next;
        free(temp);
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    for (int i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertAtLocation(&head, 10, 1);
    insertAtLocation(&head, 20, 2);
    insertAtLocation(&head, 30, 2);
    insertAtLocation(&head, 40, 3);

    printf("Linked list after inserting nodes at user-given locations: \n");
    printList(head);

    deleteAtLocation(&head, 3);
    deleteAtLocation(&head, 1);

    printf("Linked list after deleting nodes from user-given locations: \n");
    printList(head);
}