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

    int allot[processes][resources], max[processes][resources], avail[resources];

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

    // Input available resources
    printf("\nEnter the Available Resources:\n");
    for (int i = 0; i < resources; i++) {
        scanf("%d", &avail[i]);
    }

    int work[resources], finish[processes];

    // Initialize work array with available resources
    for (int i = 0; i < resources; i++) {
        work[i] = avail[i];
    }

    // Initialize finish array to 0 (not finished)
    for (int i = 0; i < processes; i++) {
        finish[i] = 0;
    }

    int count = 0;  // Count of finished processes
    bool safeState = true;

    while (count < processes) {
        bool found = false;

        // Try to find a process that can be finished
        for (int p = 0; p < processes; p++) {
            if (finish[p] == 0) {  // If process is not finished
                bool canFinish = true;

                // Check if the process can be finished
                for (int r = 0; r < resources; r++) {
                    if (max[p][r] - allot[p][r] > work[r]) {
                        canFinish = false;
                        break;
                    }
                }

                if (canFinish) {
                    // If process can finish, simulate resource release
                    for (int r = 0; r < resources; r++) {
                        work[r] += allot[p][r];
                    }
                    finish[p] = 1;  // Mark process as finished
                    found = true;
                    count++;
                }
            }
        }

        // If no process could be finished, system is in deadlock
        if (!found) {
            safeState = false;
            break;
        }
    }

    // Output result
    if (safeState) {
        printf("\nThe system is in a safe state.\n");
    } else {
        printf("\nThe system is not in a safe state.\n");
    }

    return 0;
}

