#include <stdio.h>
#include <string.h>

#include "modules/node/node_manager.h"
#include "modules/replication/replication_manager.h"
#include "modules/failure/failure_detector.h"
#include "modules/index/index_manager.h"
#include "modules/storage/storage.h"
#include "modules/stats/stats.h"

int main() {

    NodeManager manager;
    IndexManager index;

    initNodeManager(&manager);
    initIndex(&index);
    initStorage();

    // Initialize nodes
    addStorageNode(&manager, 1);
    addStorageNode(&manager, 2);
    addStorageNode(&manager, 3);

	// persist storege
	for (int i = 0; i < manager.ring.count; i++) {
    	int nodeId = manager.ring.nodes[i].nodeId;
    	StorageNode* node = getNodeById(&manager, nodeId);
    	loadFromFileWithIndex(node, nodeId, &index);
	}

    int choice, key, nodeId;
    char value[100];

    while (1) {

        printf("\n==== MENU ====\n");
        printf("1. Insert Data\n");
        printf("2. Get Data\n");
        printf("3. Search by Value\n");
        printf("4. Show Nodes\n");
        printf("5. Simulate Node Failure\n");
        printf("6. Recover Node\n");
        printf("7. Show Stats\n");
        printf("8. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);


        switch (choice) {


        case 1:
            printf("Enter key: ");
            scanf("%d", &key);

            printf("Enter value: ");
            scanf("%s", value);

            putWithReplication(&manager, key, value);
            insertIndex(&index, value, key);
            break;

        case 2:
            printf("Enter key: ");
            scanf("%d", &key);

            {
                char* val = getWithReplication(&manager, key);

                if (val)
                    printf("Value: %s\n", val);
                else
                    printf("Not found\n");
            }
            break;

        case 3:
            printf("Enter value: ");
            scanf("%s", value);

            key = searchIndex(&index, value);

            if (key != -1) {
                char* val = getWithReplication(&manager, key);
                printf("Found: %s\n", val);
            } else {
                printf("Not found\n");
            }
            break;

        case 4:
            displayNodes(&manager);
            break;

        case 5:
            printf("Enter node ID to fail: ");
            scanf("%d", &nodeId);
            markNodeDown(&manager, nodeId);
            break;

        case 6:
            printf("Enter node ID to recover: ");
            scanf("%d", &nodeId);
            markNodeUp(&manager, nodeId);
            break;

        case 7:
            displayStats(&manager);
            displayLoadDistribution(&manager);
            break;

        case 8:
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }
}