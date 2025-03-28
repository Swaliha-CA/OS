#include<stdio.h>
#include<stdlib.h>

void main() {
    int n, q[100], i, diff, seek = 0;
    
    printf("Enter the size of queue: ");
    scanf("%d", &n);
    
    printf("Enter the queue: ");
    for (i = 1; i < n; i++) {
        scanf("%d", &q[i]);
    }
    
    printf("Enter the initial head position: ");
    scanf("%d", &q[0]);
    
    for (i = 0; i < n - 1; i++) {
        diff = abs(q[i] - q[i + 1]);
        seek += diff;
    }
    
    printf("\nTotal seek distance is: %d", seek);
    
    float avg = (float)seek / (n - 1);
    printf("\nAverage seek distance is: %.3f\n", avg);
} 

