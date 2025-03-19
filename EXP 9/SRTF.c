#include <stdio.h>

void main() {
    int n, at[10], bt[10], rt[10], ct[10], tt[10], wt[10];
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
        rt[i] = bt[i];
    }

    printf("\nGantt chart\n");
    printf("-------------------------------------------------\n");

    while (complete < n) {
        shortest = -1;
        min_rt = 9999;

        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0 && rt[i] < min_rt) {
                shortest = i;
                min_rt = rt[i];
            }
        }

        if (shortest == -1) {
            time++;
            continue;
        }

        printf("  P%d  |", shortest + 1);
        rt[shortest]--;
        time++;

        if (rt[shortest] == 0) {
            complete++;
            ct[shortest] = time;
        }
    }

    printf("\n-------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        wt[i] = ct[i] - at[i] - bt[i]; 
        tt[i] = ct[i] - at[i];          
        avg_wt += wt[i];
        avg_tt += tt[i];
    }

    printf("\nProcess\tAT\tBT\tCT\tTT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tt[i], wt[i]);
    }

    printf("\nAverage Turnaround Time: %.2f", avg_tt / n);
    printf("\nAverage Waiting Time: %.2f\n", avg_wt / n);
}
