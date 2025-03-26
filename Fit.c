#include <stdio.h>

int main() {
    int m, n, choice;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);
    int blockSize[m], tempBlockSize[m];  // To store original block sizes

    printf("Enter the size of each memory block: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &blockSize[i]);
        tempBlockSize[i] = blockSize[i]; // Store original sizes for later use
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int processSize[n], allocation[n];

    printf("Enter the size of each process: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &processSize[i]);
        allocation[i] = -1; // Initialize allocation array
    }

    printf("\nChoose allocation technique:\n");
    printf("1. Worst-Fit\n2. Best-Fit\n3. First-Fit\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {  // **Worst-Fit**
        for (int i = 0; i < n; i++) {
            int worstIdx = -1;
            for (int j = 0; j < m; j++) {
                if (blockSize[j] >= processSize[i]) {
                    if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx])
                        worstIdx = j;
                }
            }
            if (worstIdx != -1) {
                allocation[i] = worstIdx;
                blockSize[worstIdx] -= processSize[i];
            }
        }
    } 
    else if (choice == 2) {  // **Best-Fit**
        for (int i = 0; i < n; i++) {
            int bestIdx = -1;
            for (int j = 0; j < m; j++) {
                if (blockSize[j] >= processSize[i]) {
                    if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                        bestIdx = j;
                }
            }
            if (bestIdx != -1) {
                allocation[i] = bestIdx;
                blockSize[bestIdx] -= processSize[i];
            }
        }
    } 
    else if (choice == 3) {  // **First-Fit**
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (blockSize[j] >= processSize[i]) {
                    allocation[i] = j;
                    blockSize[j] -= processSize[i];
                    break;
                }
            }
        }
    } 
    else {
        printf("Invalid choice!\n");
        return 0;
    }

    // **Display allocation result**
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
