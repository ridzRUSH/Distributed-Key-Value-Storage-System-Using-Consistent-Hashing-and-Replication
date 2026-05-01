#ifndef INDEX_MANAGER_H
#define INDEX_MANAGER_H

#include "../ds/trie.h"

typedef struct {
    TrieNode* root;
} IndexManager;

// APIs
void initIndex(IndexManager* index);
void insertIndex(IndexManager* index, char* value, int key);
int searchIndex(IndexManager* index, char* value);

#endif