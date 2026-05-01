#ifndef TRIE_H
#define TRIE_H

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    int isEnd;
    int key;
} TrieNode;

// APIs
TrieNode* createTrieNode();
void insertTrie(TrieNode* root, char* word, int key);
int searchTrie(TrieNode* root, char* word);
void freeTrie(TrieNode* root);

#endif