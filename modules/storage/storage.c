#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "storage.h"
#include "../node/node_manager.h"
#include "../index/index_manager.h"
#include "../encryption/encryption.h"

// Initialize storage (create log file if not exists)
void initStorage() {
    FILE* fp = fopen("logs/operations.log", "a");
    if (fp) fclose(fp);
}

// Save data to node file
void saveToFile(int nodeId, int key, char* value) {
    char filename[50];

    sprintf(filename, "data/node%d.txt", nodeId);

    FILE* fp = fopen(filename, "a");

    if (!fp) {
        printf("Error opening %s\n", filename);
        return;
    }

    fprintf(fp, "%d %s\n", key, value);

    fclose(fp);
}

// Log operation
void logOperation(char* message) {
    FILE* fp = fopen("logs/operations.log", "a");

    if (!fp) {
        printf("Error opening log file\n");
        return;
    }

    time_t t = time(NULL);

    fprintf(fp, "%s : %s\n", strtok(ctime(&t), "\n"), message);

    fclose(fp);
}

// load back data
void loadFromFileWithIndex(StorageNode* node, int nodeId, IndexManager* index) {
    char filename[50];
    sprintf(filename, "data/node%d.txt", nodeId);

    FILE* file = fopen(filename, "r");
    if (!file) return;

    int key;
    char value[100];

    while (fscanf(file, "%d %s", &key, value) != EOF) {

        put(node->store, key, value);
		char decrypted[100];
		strcpy(decrypted, value);
    	decrypt(decrypted);

    	insertIndex(index, decrypted, key);
    }

    fclose(file);
}