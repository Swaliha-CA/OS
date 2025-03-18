#include <stdio.h>

void main() {
    int p[10], wt[10], tt[10], n, bt[10], at[10], ct[10]; // Added ct for completion time
    float avg_tt = 0.0, avg_wt = 0.0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time and arrival time of each process:\n");
    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Process p%d - Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
        printf("Process p%d - Arrival Time: ", i + 1);
        scanf("%d", &at[i]);
    }

    // Initialize waiting time for the first process
    wt[0] = 0;
    ct[0] = at[0] + bt[0]; // Completion time for the first process

    // Calculate waiting time and completion time
    for (int i = 1; i < n; i++) {
        // Calculate waiting time
        wt[i] = ct[i - 1] - at[i];
        if (wt[i] < 0) {
            wt[i] = 0; // If the process arrives after the previous one finishes
        }
        // Calculate completion time
        ct[i] = at[i] + bt[i] + wt[i];
        avg_wt += wt[i];
    }

    avg_wt /= n;

    // Calculate turnaround time and average turnaround time
    for (int i = 0; i < n; i++) {
        tt[i] = wt[i] + bt[i];
        avg_tt += tt[i];
    }

    avg_tt /= n;

    // Print the results
    printf("\nProcess\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    for (int i = 0; i < n; i++) {
        printf("p%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], at[i], wt[i], tt[i], ct[i]);
    }

    printf("\nAverage waiting time: %.2f\n", avg_wt);
    printf("Average turnaround time: %.2f\n", avg_tt);

    // Print Gantt chart
    printf("\nGantt chart\n\n");
    printf("\n----------------------\n");

    // Print process names in Gantt chart
    for (int i = 0; i < n; i++) {
        printf("\t p%d\t||", p[i]);
    }

    printf("\n----------------------\n");

    // Print completion times in Gantt chart
    for (int i = 0; i < n; i++) {
        printf("\t%d\t", ct[i]);
    }

    printf("\n----------------------\n");
}
