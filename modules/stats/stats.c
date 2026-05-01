#include <stdio.h>
#include "stats.h"

// Count keys in a node
int countKeys(StorageNode* node) {
    int count = 0;

    for (int i = 0; i < node->store->capacity; i++) {
        Node* curr = node->store->buckets[i];

        while (curr != NULL) {
            count++;
            curr = curr->next;
        }
    }

    return count;
}

// Display stats
void displayStats(NodeManager* manager) {
    int total = 0;

    printf("\n--- SYSTEM STATS ---\n");

    for (int i = 0; i < manager->count; i++) {
        StorageNode* node = &manager->nodes[i];

        int keys = countKeys(node);
        total += keys;

        printf("Node %d | Keys: %d | %s\n",
               node->nodeId,
               keys,
               node->isActive ? "ACTIVE" : "DOWN");
    }

    printf("Total Keys: %d\n", total);
}

// Load distribution (visual)
void displayLoadDistribution(NodeManager* manager) {
    printf("\n--- LOAD DISTRIBUTION ---\n");

    for (int i = 0; i < manager->count; i++) {
        StorageNode* node = &manager->nodes[i];

        int keys = countKeys(node);

        printf("Node %d: ", node->nodeId);

        for (int j = 0; j < keys; j++) {
            printf("*");
        }

        printf(" (%d)\n", keys);
    }
}