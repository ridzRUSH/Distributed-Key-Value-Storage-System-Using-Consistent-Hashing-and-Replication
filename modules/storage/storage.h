#ifndef STORAGE_H
#define STORAGE_H

void initStorage();
void saveToFile(int nodeId, int key, char* value);
void logOperation(char* message);

#endif