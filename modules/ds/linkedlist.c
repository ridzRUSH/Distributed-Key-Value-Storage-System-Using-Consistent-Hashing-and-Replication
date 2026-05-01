#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

// Create new node
Node* createNode(int key, char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->key = key;
    strcpy(newNode->value, value);
    newNode->next = NULL;

    return newNode;
}

// Insert (update if exists, else insert at head)
Node* insertNode(Node* head, int key, char* value) {
    Node* curr = head;

    while (curr != NULL) {
        if (curr->key == key) {
            strcpy(curr->value, value);
            return head;
        }
        curr = curr->next;
    }

    Node* newNode = createNode(key, value);
    newNode->next = head;

    return newNode;
}

// Search
char* searchNode(Node* head, int key) {
    Node* curr = head;

    while (curr != NULL) {
        if (curr->key == key) {
            return curr->value;
        }
        curr = curr->next;
    }

    return NULL;
}

// Free memory
void freeList(Node* head) {
    Node* curr = head;

    while (curr != NULL) {
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
}