#ifndef CONSISTENT_HASH_H
#define CONSISTENT_HASH_H

#define MAX_NODES 20

typedef struct {
    int nodeId;
    int hash;
} RingNode;

typedef struct {
    RingNode nodes[MAX_NODES];
    int count;
} HashRing;

// APIs
void initRing(HashRing* ring);
void addNode(HashRing* ring, int nodeId);
int getNode(HashRing* ring, int key);
void displayRing(HashRing* ring);

#endif