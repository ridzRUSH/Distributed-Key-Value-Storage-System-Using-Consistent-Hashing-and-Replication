#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "index_manager.h"

// Convert string to lowercase
void toLowerCase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Init index
void initIndex(IndexManager* index) {
    index->root = createTrieNode();
}

// Insert value → key
void insertIndex(IndexManager* index, char* value, int key) {
    char temp[100];
    strcpy(temp, value);

    toLowerCase(temp);

    insertTrie(index->root, temp, key);
}

// Search value → key
int searchIndex(IndexManager* index, char* value) {
    char temp[100];
    strcpy(temp, value);

    toLowerCase(temp);

    return searchTrie(index->root, temp);
}