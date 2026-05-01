#include <stdio.h>
#include <stdlib.h>
#include "hashmap.h"

#define LOAD_FACTOR 0.75

// Hash function
int hash(int key, int capacity) {
    return key % capacity;
}

// Create map
HashMap* createMap(int capacity) {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));

    map->capacity = capacity;
    map->size = 0;

    map->buckets = (Node**)malloc(sizeof(Node*) * capacity);

    for (int i = 0; i < capacity; i++) {
        map->buckets[i] = NULL;
    }

    return map;
}

// Resize map
void resize(HashMap* map) {
    int newCapacity = map->capacity * 2;

    Node** newBuckets = (Node**)malloc(sizeof(Node*) * newCapacity);

    for (int i = 0; i < newCapacity; i++) {
        newBuckets[i] = NULL;
    }

    // Rehash
    for (int i = 0; i < map->capacity; i++) {
        Node* curr = map->buckets[i];

        while (curr != NULL) {
            Node* next = curr->next;

            int index = hash(curr->key, newCapacity);

            curr->next = newBuckets[index];
            newBuckets[index] = curr;

            curr = next;
        }
    }

    free(map->buckets);
    map->buckets = newBuckets;
    map->capacity = newCapacity;
}

// Put
void put(HashMap* map, int key, char* value) {
    int index = hash(key, map->capacity);

    map->buckets[index] = insertNode(map->buckets[index], key, value);

    map->size++;

    if ((float)map->size / map->capacity > LOAD_FACTOR) {
        resize(map);
    }
}

// Get
char* get(HashMap* map, int key) {
    int index = hash(key, map->capacity);
    return searchNode(map->buckets[index], key);
}

// Free map
void freeMap(HashMap* map) {
    for (int i = 0; i < map->capacity; i++) {
        freeList(map->buckets[i]);
    }

    free(map->buckets);
    free(map);
}