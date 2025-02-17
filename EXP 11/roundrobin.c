#include <stdio.h>

void main() {
    int at[10], bt[10], ct[10], tt[10], wt[10], rt[10], n, q, complete = 0;
    int time = 0;
    float avg_tt = 0, avg_wt = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter arrival times:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &at[i]);
    }

    printf("Enter burst times:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];  // Initialize remaining time with burst time
    }

    printf("Enter the time quantum: ");
    scanf("%d", &q);

    printf("\nGantt chart\n");
    printf("-------------------------------------------------\n");

    // Round Robin scheduling
    while (complete < n) {
        int done = 1;  // Flag to check if all processes are done in this cycle

        for (int i = 0; i < n; i++) {
            // Check if the process has arrived and has remaining burst time
            if (at[i] <= time && rt[i] > 0) {
                done = 0;

                printf("P%d |", i + 1);  // Print process in the Gantt chart

                if (rt[i] > q) {
                    rt[i] -= q;     // Process runs for a time quantum
                    time += q;
                } else {
                    time += rt[i];  // Process finishes within its remaining time
                    rt[i] = 0;      // Mark process as completed
                    ct[i] = time;   // Store completion time
                    complete++;     // Increment complete count
                }
            }
        }

        // If all processes are completed, break out of the loop
        if (done) {
            break;
        }
    }

    printf("\n-------------------------------------------------\n");

    // Calculate Turnaround Time and Waiting Time
    for (int i = 0; i < n; i++) {
        tt[i] = ct[i] - at[i];   // Turnaround Time = Completion Time - Arrival Time
        wt[i] = tt[i] - bt[i];   // Waiting Time = Turnaround Time - Burst Time
        avg_wt += wt[i];
        avg_tt += tt[i];
    }

    // Display process details
    printf("\nProcess\tAT\tBT\tCT\tTT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tt[i], wt[i]);
    }

    // Display Average Waiting Time and Average Turnaround Time
    printf("\nAverage Turnaround Time: %.2f", avg_tt / n);
    printf("\nAverage Waiting Time: %.2f\n", avg_wt / n);
}

