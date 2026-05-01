#include <stdio.h>
#include "failure_detector.h"

// Mark node DOWN
void markNodeDown(NodeManager* manager, int nodeId) {
    StorageNode* node = getNodeById(manager, nodeId);

    if (node) {
        node->isActive = 0;
        printf("Node %d marked DOWN\n", nodeId);
    } else {
        printf("Node %d not found\n", nodeId);
    }
}

// Mark node ACTIVE
void markNodeUp(NodeManager* manager, int nodeId) {
    StorageNode* node = getNodeById(manager, nodeId);

    if (node) {
        node->isActive = 1;
        printf("Node %d marked ACTIVE\n", nodeId);
    } else {
        printf("Node %d not found\n", nodeId);
    }
}

// Check node status
int isNodeActive(NodeManager* manager, int nodeId) {
    StorageNode* node = getNodeById(manager, nodeId);

    if (node) return node->isActive;

    return 0;
}

// Display status
void displayNodeStatus(NodeManager* manager) {
    printf("\n--- NODE STATUS ---\n");

    for (int i = 0; i < manager->count; i++) {
        printf("Node %d-> %s\n",
               manager->nodes[i].nodeId,
               manager->nodes[i].isActive ? "ACTIVE" : "DOWN");
    }
}