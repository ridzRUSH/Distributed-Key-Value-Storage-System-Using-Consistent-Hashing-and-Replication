#ifndef FAILURE_DETECTOR_H
#define FAILURE_DETECTOR_H

#include "../node/node_manager.h"

// APIs
void markNodeDown(NodeManager* manager, int nodeId);
void markNodeUp(NodeManager* manager, int nodeId);
int isNodeActive(NodeManager* manager, int nodeId);
void displayNodeStatus(NodeManager* manager);

#endif