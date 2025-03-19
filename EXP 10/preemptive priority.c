#include <stdio.h>

int main() {
    int n, at[10], bt[10], rt[10], ct[10], tt[10], wt[10], pr[10];
    int complete = 0, time = 0, shortest = -1, min_rt;
    float avg_wt = 0, avg_tt = 0;

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
        rt[i] = bt[i]; // Remaining time initialized to burst time
    }

    printf("Enter priorities (lower number indicates higher priority):\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &pr[i]);
    }

    printf("\nGantt chart\n");
    printf("-------------------------------------------------\n");

    while (complete < n) {
        shortest = -1;
        min_rt = 9999;

        for (int i = 0; i < n; i++) {
            // Check if the process has arrived and has remaining time
            if (at[i] <= time && rt[i] > 0) {
                // Select the process with the shortest remaining time
                // If remaining times are equal, select the one with higher priority
                if (rt[i] < min_rt || (rt[i] == min_rt && pr[i] < pr[shortest])) {
                    shortest = i;
                    min_rt = rt[i];
                }
            }
        }

        if (shortest == -1) {
            time++;
            continue;
        }

        printf("  P%d  |", shortest + 1);
        rt[shortest]--; // Decrease remaining time
        time++;

        if (rt[shortest] == 0) {
            complete++;
            ct[shortest] = time; // Completion time
        }
    }

    printf("\n-------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        tt[i] = ct[i] - at[i];          // Turnaround Time
        wt[i] = tt[i] - bt[i];          // Waiting Time
        avg_wt += wt[i];
        avg_tt += tt[i];
    }

    printf("\nProcess\tAT\tBT\tCT\tTT\tWT\tPriority\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tt[i], wt[i], pr[i]);
    }

    printf("\nAverage Turnaround Time: %.2f", avg_tt / n);
    printf("\nAverage Waiting Time: %.2f\n", avg_wt / n);

    return 0; 
}
