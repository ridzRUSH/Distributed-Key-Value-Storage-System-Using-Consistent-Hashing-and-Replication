#ifndef STATS_H
#define STATS_H

#include "../node/node_manager.h"

// APIs
int countKeys(StorageNode* node);
void displayStats(NodeManager* manager);
void displayLoadDistribution(NodeManager* manager);

#endif