#include <stdio.h>
#include <string.h>

#include "replication_manager.h"
#include "../storage/storage.h"
#include "../encryption/encryption.h"

// Helper: get replica node
int getReplicaNodeId(HashRing* ring, int primaryId) {
    for (int i = 0; i < ring->count; i++) {
        if (ring->nodes[i].nodeId == primaryId) {
            return ring->nodes[(i + 1) % ring->count].nodeId;
        }
    }
    return -1;
}

// PUT with replication (ENCRYPT HERE)
void putWithReplication(NodeManager* manager, int key, char* value) {

    int primaryId = getNode(&manager->ring, key);
    StorageNode* primary = getNodeById(manager, primaryId);

    if (primary && primary->isActive) {

        char temp[100];
        strcpy(temp, value);

        encrypt(temp);   

        put(primary->store, key, temp);
        saveToFile(primaryId, key, temp);

        logOperation("Write to PRIMARY node");

        printf("Stored in PRIMARY Node %d\n", primaryId);
    }

    int replicaId = getReplicaNodeId(&manager->ring, primaryId);
    StorageNode* replica = getNodeById(manager, replicaId);

    if (replica && replica->isActive) {

        char temp[100];
        strcpy(temp, value);

        encrypt(temp);

        put(replica->store, key, temp);
		saveToFile(replicaId, key, temp);

        logOperation("Write to REPLICA node");

        printf("Stored in REPLICA Node %d\n", replicaId);
    }
}

// GET with failover (DECRYPT HERE)
char* getWithReplication(NodeManager* manager, int key) {

    int primaryId = getNode(&manager->ring, key);
    StorageNode* primary = getNodeById(manager, primaryId);

    // Try primary
    if (primary && primary->isActive) {
        char* val = get(primary->store, key);

        if (val != NULL) {

            static char decrypted[100];
            strcpy(decrypted, val);

            decrypt(decrypted);   

            printf("Fetched from PRIMARY Node %d\n", primaryId);
            return decrypted;
        }
    }

    // Try replica
    int replicaId = getReplicaNodeId(&manager->ring, primaryId);
    StorageNode* replica = getNodeById(manager, replicaId);

    if (replica && replica->isActive) {
        char* val = get(replica->store, key);

        if (val != NULL) {

            static char decrypted[100];
            strcpy(decrypted, val);

            decrypt(decrypted);   

            printf("Fetched from REPLICA Node %d\n", replicaId);
            return decrypted;
        }
    }

    printf("Data not found\n");
    return NULL;
}