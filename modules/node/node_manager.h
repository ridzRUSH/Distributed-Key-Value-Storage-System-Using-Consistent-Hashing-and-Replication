#ifndef NODE_MANAGER_H
#define NODE_MANAGER_H

#include "../ds/hashmap.h"
#include "../hashing/consistent_hash.h"
#include "../../config.h"


typedef struct {
    int nodeId;
    int isActive;
    HashMap* store;
} StorageNode;

typedef struct {
    StorageNode nodes[MAX_STORAGE_NODES];
    int count;
    HashRing ring;
} NodeManager;

// APIs
void initNodeManager(NodeManager* manager);
void addStorageNode(NodeManager* manager, int nodeId);
StorageNode* getNodeById(NodeManager* manager, int nodeId);

void putData(NodeManager* manager, int key, char* value);
char* getData(NodeManager* manager, int key);

void displayNodes(NodeManager* manager);

#endif