#ifndef STORAGE_H
#define STORAGE_H
#include "../node/node_manager.h"
#include "../index/index_manager.h"

void initStorage();
void saveToFile(int nodeId, int key, char* value);
void logOperation(char* message);
void loadFromFileWithIndex(StorageNode* node, int nodeId, IndexManager* index);

#endif