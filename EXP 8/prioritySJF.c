#include <stdio.h>

int main() {
    int p[10], wt[10], tt[10], ct[10], n, bt[10], at[10], pr[10];
    float avg_tt = 0.0, avg_wt = 0.0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input arrival times
    printf("Enter the arrival time of each process:\n");
    for (int i = 0; i < n; i++) {
        p[i] = i + 1; // Initialize process numbers
        printf("p%d: ", i + 1);
        scanf("%d", &at[i]);
    }

    // Input burst times
    printf("Enter the burst time of each process:\n");
    for (int i = 0; i < n; i++) {
        printf("p%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Input priority
    printf("Enter the priority of each process:\n");
    for (int i = 0; i < n; i++) {
        printf("p%d: ", i + 1);
        scanf("%d", &pr[i]);
    }

    // Sorting processes based on their arrival time and priority
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[i] > at[j] || (at[i] == at[j] && pr[i] > pr[j])) {
                // Swap arrival times
                int temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                // Swap burst times accordingly
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // Swap priorities
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

                // Swap process numbers accordingly
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Initialize waiting time for the first process
    wt[0] = 0;
    ct[0] = at[0] + bt[0];  // Completion time of first process

    for (int i = 1; i < n; i++) {
        // Waiting time = (previous completion time - arrival time)
        wt[i] = ct[i - 1] - at[i];
        if (wt[i] < 0) {
            wt[i] = 0; // If waiting time is negative, set to 0
        }

        // Completion time = waiting time + burst time + arrival time
        ct[i] = at[i] + wt[i] + bt[i];
        avg_wt += wt[i];
    }

    avg_wt /= n; // Calculate average waiting time

    // Calculate turnaround times
    for (int i = 0; i < n; i++) {
        tt[i] = ct[i] - at[i];  // Turnaround time = Completion time - Arrival time
        avg_tt += tt[i];
    }

    avg_tt /= n; // Calculate average turnaround time

    // Output process details including completion time
    printf("\nProcess\tAT\tBT\tPriority\tCT\tTT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("p%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n", p[i], at[i], bt
