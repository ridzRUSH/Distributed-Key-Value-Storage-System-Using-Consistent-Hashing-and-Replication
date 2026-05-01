#include <stdio.h>
#include "consistent_hash.h"

// Better hash function
// Knuth multiplicative hash constant
// Deterministic
int hashFunction(int key) {
    return (key * 2654435761) % 360;
}

// Init ring
void initRing(HashRing* ring) {
    ring->count = 0;
}

// Add node (sorted insert)
void addNode(HashRing* ring, int nodeId) {
    if (ring->count >= MAX_NODES) {
        printf("Max nodes reached\n");
        return;
    }

    int hash = hashFunction(nodeId);

    int i = ring->count - 1;

    while (i >= 0 && ring->nodes[i].hash > hash) {
        ring->nodes[i + 1] = ring->nodes[i];
        i--;
    }

    ring->nodes[i + 1].nodeId = nodeId;
    ring->nodes[i + 1].hash = hash;

    ring->count++;
}

// Get node for key
int getNode(HashRing* ring, int key) {
    if (ring->count == 0) return -1;

    int hash = hashFunction(key);

    // Find first clockwise node
    for (int i = 0; i < ring->count; i++) {
        if (hash <= ring->nodes[i].hash) {
            return ring->nodes[i].nodeId;
        }
    }

    // Wrap around
    return ring->nodes[0].nodeId;
}

// Display ring
void displayRing(HashRing* ring) {
    printf("\n--- HASH RING ---\n");

    for (int i = 0; i < ring->count; i++) {
        printf("Node %d-> Hash %d\n",
               ring->nodes[i].nodeId,
               ring->nodes[i].hash);
    }
}