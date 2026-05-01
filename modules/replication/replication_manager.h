#ifndef REPLICATION_MANAGER_H
#define REPLICATION_MANAGER_H

#include "../node/node_manager.h"
#include "../encryption/encryption.h"

// APIs
void putWithReplication(NodeManager* manager, int key, char* value);
char* getWithReplication(NodeManager* manager, int key);

#endif