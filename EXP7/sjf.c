#include <stdio.h>
#include <string.h>

typedef struct process {
    int pid;
    char pname[10];
    int at; 
    int bt;  
    int ct;  
    int tt;  
    int wt;  
} sjf;

void getProcess(sjf p[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter the %d Process PID: ", i + 1);
        scanf("%d", &p[i].pid);
        printf("Enter the %d Process Name: ", i + 1);
        scanf("%s", p[i].pname);
        printf("Enter the %d Process Arrival Time: ", i + 1);
        scanf("%d", &p[i].at);
        printf("Enter the %d Process Burst Time: ", i + 1);
        scanf("%d", &p[i].bt);
    }
}


void sortProcesses(sjf p[], int n) {
    sjf temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at || 
               (p[j].at == p[j + 1].at && p[j].bt > p[j + 1].bt)) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void computeCompletionTime(sjf p[], int n) {
    int time = 0;
    for (int i = 0; i < n; i++) {
        if (time < p[i].at) {
            time = p[i].at;
        }
        time += p[i].bt;
        p[i].ct = time;
    }
}

void computeTurnaroundTime(sjf p[], int n) {
    for (int i = 0; i < n; i++) {
        p[i].tt = p[i].ct - p[i].at;
    }
}

void computeWaitingTime(sjf p[], int n) {
    for (int i = 0; i < n; i++) {
        p[i].wt = p[i].tt - p[i].bt;
    }
}

void printProcesses(sjf p[], int n) {
    printf("\nPID\tName\tAT\tBT\tCT\tTT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].pname, p[i].at, p[i].bt, p[i].ct, p[i].tt, p[i].wt);
    }
}

void ganttChart(sjf p[], int n) {
    printf("\nGantt Chart:\n");

    int time = 0;
    for (int i = 0; i < n; i++) {
        if (time < p[i].at) {
            printf("| IDLE ");
            time = p[i].at;
        }
        printf("| %s ", p[i].pname);
        time += p[i].bt;
    }
    printf("|\n");

    printf("0");
    time = 0;
    for (int i = 0; i < n; i++) {
        if (time < p[i].at) {
            printf("       ");
            time = p[i].at;
        }
        time += p[i].bt;
        printf("    %d", time);
    }
    printf("\n");
}

int main() {
    sjf p[100];
    int n;
    float avgTT = 0, avgWT = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter details of processes:\n");
    getProcess(p, n);

    sortProcesses(p, n);
    computeCompletionTime(p, n);
    computeTurnaroundTime(p, n);
    computeWaitingTime(p, n);
    
    ganttChart(p, n);
    printProcesses(p, n);

    for (int i = 0; i < n; i++) {
        avgTT += p[i].tt;
        avgWT += p[i].wt;
    }

    printf("Average Turnaround Time: %.2f\n", avgTT / n);
    printf("Average Waiting Time: %.2f\n", avgWT / n);

    return 0;
}
