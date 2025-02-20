#include <stdio.h>

void main() {
    int p[10], wt[10], tt[10], n, bt[10], at[10], ct[10], completed[10];
    float avg_tt = 0.0, avg_wt = 0.0;
    int completedCount = 0, time = 0;

    // Input the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input the arrival times for the processes
    printf("Enter the arrival time of each process:\n");
    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("p%d: ", i + 1);
        scanf("%d", &at[i]);
    }

    // Input the burst times for the processes
    printf("Enter the burst time of each process:\n");
    for (int i = 0; i < n; i++) {
        printf("p%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Initialize completed array
    for (int i = 0; i < n; i++) {
        completed[i] = 0;  // Set all processes as not completed
    }

    // Sort the processes based on arrival time
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {
                int temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Main loop for processing SJF
    while (completedCount != n) {
        int shortest = -1;
        int min_bt = 9999;

        // Find the process with the smallest burst time that has arrived
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && completed[i] == 0 && bt[i] < min_bt) {
                min_bt = bt[i];
                shortest = i;
            }
        }

        if (shortest != -1) {
            // Update the completion time, waiting time, and turnaround time
            time += bt[shortest];  // Increment time by burst time of current process
            ct[shortest] = time;    // Set completion time

            wt[shortest] = ct[shortest] - at[shortest] - bt[shortest];  // Waiting time = Completion - Arrival - Burst
            tt[shortest] = ct[shortest] - at[shortest];  // Turnaround time = Completion - Arrival
            avg_wt += wt[shortest];
            avg_tt += tt[shortest];

            completed[shortest] = 1;  // Mark the process as completed
            completedCount++;         // Increase completed processes count
        } else {
            time++;  // If no process is ready, just increment time
        }
    }

    // Calculate averages
    avg_wt /= n;
    avg_tt /= n;

    // Output process details
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    for (int i = 0; i < n; i++) {
        printf("p%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i], at[i], bt[i], wt[i], tt[i], ct[i]);
    }

    // Display average waiting time and average turnaround time
    printf("\nAverage waiting time: %.2f\n", avg_wt);
    printf("Average turnaround time: %.2f\n", avg_tt);

    // Gantt chart
    printf("\nGantt chart\n\n");
    printf("\n--------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("\t p%d\t||", p[i]);
    }
    printf("\n---------------------------------------------------------------------\n");

    printf("0");
    for (int i = 0; i < n; i++) {
        printf("\t\t%d", ct[i]);
    }
    printf("\n");
}
