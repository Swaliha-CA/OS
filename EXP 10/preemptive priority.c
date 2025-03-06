#include <stdio.h>

void main() {
    int n, at[10], bt[10], pr[10], rt[10], ct[10], tt[10], wt[10];
    int complete = 0, time = 0, highest = -1, min_pr;
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

    printf("Enter priorities (lower number = higher priority):\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &pr[i]);
    }

    printf("\nGantt chart\n");
    printf("-------------------------------------------------\n");

    while (complete < n) {
        highest = -1;
        min_pr = 9999;

        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0 && pr[i] < min_pr) {
                highest = i;
                min_pr = pr[i];
            }
        }

        if (highest == -1) {
            time++;
            continue;
        }

        printf("  P%d  |", highest + 1);
        rt[highest]--;
        time++;

        if (rt[highest] == 0) {
            complete++;
            ct[highest] = time;
        }
    }

    printf("\n-------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        wt[i] = ct[i] - at[i];          
        tt[i] = wt[i] - bt[i];          
        avg_wt += wt[i];
        avg_tt += tt[i];
    }

    printf("\nProcess\tAT\tBT\tPr\tCT\tTT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], pr[i], ct[i], tt[i], wt[i]);
    }

    printf("\nAverage Turnaround Time: %.2f", avg_tt / n);
    printf("\nAverage Waiting Time: %.2f\n", avg_wt / n);
}
