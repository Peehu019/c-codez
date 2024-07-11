#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}; 

// Function to traverse the list forward
void traverseForward(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to traverse the list backward
void traverseBackward(struct Node *node) {
    while (node->next != NULL) {
        node = node->next;
    }
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->prev;
    }
    printf("\n");
}

void insertAtBeginning(struct Node **headRef, int newData) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = *headRef;
    if (*headRef != NULL) {
        (*headRef)->prev = newNode;
    }
    *headRef = newNode;
}

void insertAtend(struct Node **headRef, int newData) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;
    struct Node *last = *headRef;
    while (last->next != NULL){
        last = last->next;
    }
    last->next = newNode;
    newNode->prev = last;
}

void insertAfter(struct Node *prevNode, int newData) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    if (prevNode->next != NULL) {
        prevNode->next->prev = newNode;
    }
    prevNode->next = newNode;
}

void deleteAtfirst(struct Node **headRef){
    struct Node *temp = *headRef;
    *headRef=(*headRef)->next;
    (*headRef)->prev=NULL;
}

void deleteAtend(struct Node **headRef){
    struct Node *temp=*headRef;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev->next=NULL;
}

void deleteAfter(struct Node *prevNode){
    struct Node *temp = prevNode->next;
    prevNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = prevNode;
    }

}

struct Node* searchNode(struct Node* head, int key) {
    struct Node* current = head; // Initialize current

    while (current != NULL) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return NULL; // The key was not present in the list
}

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;
    head->prev = NULL;

    second->data = 2;
    second->next = third;
    second->prev = head;

    third->data = 3;
    third->next = NULL;
    third->prev = second;

    insertAtBeginning(&head, 5);
    insertAtend(&head, 4);
    insertAfter(head, 6);
    deleteAtfirst(&head);
    deleteAtend(&head);
    deleteAfter(second);
    int key = 7;
    struct Node* found = searchNode(head, key);

    if (found != NULL) {
        printf("Node with data %d found.\n", key);
    } else {
        printf("Node with data %d not found.\n", key);
    }

    printf("Traverse forward:\n");
    traverseForward(head);

    printf("Traverse backward:\n");
    traverseBackward(head);

    return 0;
}
