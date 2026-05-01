#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

// Create node
TrieNode* createTrieNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));

    node->isEnd = 0;
    node->key = -1;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }

    return node;
}

// Insert
void insertTrie(TrieNode* root, char* word, int key) {
    TrieNode* curr = root;

    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';

        if (index < 0 || index >= ALPHABET_SIZE)
            continue;

        if (!curr->children[index]) {
            curr->children[index] = createTrieNode();
        }

        curr = curr->children[index];
    }

    curr->isEnd = 1;
    curr->key = key;
}

// Search
int searchTrie(TrieNode* root, char* word) {
    TrieNode* curr = root;

    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';

        if (index < 0 || index >= ALPHABET_SIZE)
            return -1;

        if (!curr->children[index])
            return -1;

        curr = curr->children[index];
    }

    if (curr && curr->isEnd)
        return curr->key;

    return -1;
}

// Free memory
void freeTrie(TrieNode* root) {
    if (!root) return;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        freeTrie(root->children[i]);
    }

    free(root);
}