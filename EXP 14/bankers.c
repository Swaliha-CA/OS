#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 5
#define MAX_RESOURCES 3

int main() {
    int processes, resources;

    printf("Enter the number of processes: ");
    scanf("%d", &processes);
    printf("Enter the number of resources: ");
    scanf("%d", &resources);

    int allot[processes][resources], max[processes][resources], need[processes][resources], avail[resources], request[resources];

    // Input allocation matrix
    printf("\nEnter the Allocation Matrix:\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            scanf("%d", &allot[i][j]);
        }
    }

    // Input max matrix
    printf("\nEnter the Max Matrix:\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Calculate need matrix
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            need[i][j] = max[i][j] - allot[i][j];
        }
    }

    // Input available resources
    printf("\nEnter the Available Resources:\n");
    for (int i = 0; i < resources; i++) {
        scanf("%d", &avail[i]);
    }

    // Safety algorithm
    int work[resources], finish[processes];
    int safeSequence[MAX_PROCESSES]; // To store the safe sequence
    int seqCount = 0;                // Counter for the safe sequence

    for (int i = 0; i < resources; i++) {
        work[i] = avail[i];
    }
    for (int i = 0; i < processes; i++) {
        finish[i] = 0;
    }

    int count = 0;
    bool safeState = true;

    while (count < processes) {
        bool found = false;

        for (int p = 0; p < processes; p++) {
            if (finish[p] == 0) { // If process is not finished
                bool canFinish = true;

                for (int r = 0; r < resources; r++) {
                    if (need[p][r] > work[r]) {
                        canFinish = false;
                        break;
                    }
                }

                if (canFinish) {
                    for (int r = 0; r < resources; r++) {
                        work[r] += allot[p][r];
                    }
                    finish[p] = 1;
                    safeSequence[seqCount++] = p; // Add process to safe sequence
                    found = true;
                    count++;
                }
            }
        }

        if (!found) {
            safeState = false;
            break;
        }
    }

    if (safeState) {
        printf("\nThe system is in a safe state.\n");
        printf("Safe Sequence: ");
        for (int i = 0; i < processes; i++) {
            printf("P%d", safeSequence[i]);
            if (i != processes - 1) {
                printf(" -> ");
            }
        }
        printf("\n");
    } else {
        printf("\nThe system is not in a safe state.\n");
    }

    // Resource request handling
    printf("\nEnter the resource request for a process (enter -1 to skip):\n");
    for (int i = 0; i < resources; i++) {
        scanf("%d", &request[i]);
    }

    // Check if the request is valid
    int process_id;
    printf("Enter the process ID making the request: ");
    scanf("%d", &process_id);

    bool validRequest = true;
    for (int i = 0; i < resources; i++) {
        if (request[i] > need[process_id][i] || request[i] > avail[i]) {
            validRequest = false;
            break;
        }
    }

    if (validRequest) {
        // Update matrices
        for (int i = 0; i < resources; i++) {
            avail[i] -= request[i];       // Reduce available resources
            allot[process_id][i] += request[i]; // Increase allocation
            need[process_id][i] -= request[i];  // Reduce need
        }

        printf("\nRequest granted. Updated matrices:\n");

        // Print updated allocation matrix
        printf("\nUpdated Allocation Matrix:\n");
        for (int i = 0; i < processes; i++) {
            for (int j = 0; j < resources; j++) {
                printf("%d ", allot[i][j]);
            }
            printf("\n");
        }

        // Print updated need matrix
        printf("\nUpdated Need Matrix:\n");
        for (int i = 0; i < processes; i++) {
            for (int j = 0; j < resources; j++) {
                printf("%d ", need[i][j]);
            }
            printf("\n");
        }

        // Print updated available resources
        printf("\nUpdated Available Resources:\n");
        for (int i = 0; i < resources; i++) {
            printf("%d ", avail[i]);
        }
        printf("\n");
    } else {
        printf("\nRequest cannot be granted. It exceeds either the need or available resources.\n");
    }

    return 0;
}
