#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node_manager.h"
#include "../../config.h"

// Initialize
void initNodeManager(NodeManager* manager) {
    manager->count = 0;
    initRing(&manager->ring);
}

// Add new node
void addStorageNode(NodeManager* manager, int nodeId) {
    if (manager->count >= MAX_STORAGE_NODES) {
        printf("Max nodes reached\n");
        return;
    }

    StorageNode node;

    node.nodeId = nodeId;
    node.isActive = ACTIVE;
    node.store = createMap(INITIAL_CAPACITY);

    manager->nodes[manager->count++] = node;

    addNode(&manager->ring, nodeId);
}

// Get node by ID
StorageNode* getNodeById(NodeManager* manager, int nodeId) {
    for (int i = 0; i < manager->count; i++) {
        if (manager->nodes[i].nodeId == nodeId) {
            return &manager->nodes[i];
        }
    }
    return NULL;
}

// PUT
void putData(NodeManager* manager, int key, char* value) {
    int nodeId = getNode(&manager->ring, key);

    StorageNode* node = getNodeById(manager, nodeId);

    if (!node || node->isActive == INACTIVE) {
        printf("Node %d is DOWN\n", nodeId);
        return;
    }

    put(node->store, key, value);

    printf("Stored key %d in Node %d\n", key, nodeId);
}

// GET
char* getData(NodeManager* manager, int key) {
    int nodeId = getNode(&manager->ring, key);

    StorageNode* node = getNodeById(manager, nodeId);

    if (!node || node->isActive == INACTIVE) {
        printf("Node %d is DOWN\n", nodeId);
        return NULL;
    }

    return get(node->store, key);
}

// Display
void displayNodes(NodeManager* manager) {
    printf("\n--- NODES ---\n");

    for (int i = 0; i < manager->count; i++) {
        printf("Node %d | %s\n",
               manager->nodes[i].nodeId,
               manager->nodes[i].isActive ? "ACTIVE" : "DOWN");
    }
}