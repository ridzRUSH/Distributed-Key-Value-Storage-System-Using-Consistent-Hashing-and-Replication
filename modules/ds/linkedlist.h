#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node {
    int key;
    char value[100];
    struct Node* next;
} Node;

// APIs
Node* createNode(int key, char* value);
Node* insertNode(Node* head, int key, char* value);
char* searchNode(Node* head, int key);
void freeList(Node* head);

#endif