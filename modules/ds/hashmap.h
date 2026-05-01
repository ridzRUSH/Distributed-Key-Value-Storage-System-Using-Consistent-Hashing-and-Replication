#ifndef HASHMAP_H
#define HASHMAP_H

#include "linkedlist.h"

typedef struct {
    Node** buckets;
    int capacity;
    int size;
} HashMap;

// APIs
HashMap* createMap(int capacity);
void put(HashMap* map, int key, char* value);
char* get(HashMap* map, int key);
void freeMap(HashMap* map);

#endif