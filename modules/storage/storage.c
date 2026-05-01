#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "storage.h"

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