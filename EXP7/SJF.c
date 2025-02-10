#include<stdio.h>  

void main()
 {     
    int p[10], wt[10], tt[10], n, bt[10];     
    float avg_tt = 0.0, avg_wt = 0.0;      

    printf("Enter the number of processes: ");     
    scanf("%d", &n);            

    printf("Enter the burst time of each process:\n");     
    for (int i = 0; i < n; i++) {         
        p[i] = i + 1;          
        printf("p%d: ", i + 1);         
        scanf("%d", &bt[i]);     
    }      

   for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (bt[i] > bt[j])
             {
               //swap burst time
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                // Swap process numbers accordingly
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
               
            }
        }
    }

    wt[0] = 0; 
    for (int i = 1; i < n; i++) {         
        wt[i] = wt[i - 1] + bt[i - 1];          
        avg_wt += wt[i];     
    }      

    avg_wt /= n;       

    for (int i = 0; i < n; i++) {         
        tt[i] = wt[i] + bt[i];          
        avg_tt += tt[i];     
    }      

    avg_tt /= n;       

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");     
    for (int i = 0; i < n; i++) {         
        printf("p%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tt[i]);     
    }          

    printf("\nAverage waiting time: %.2f\n", avg_wt);     
    printf("Average turnaround time: %.2f\n", avg_tt);      

    printf("\nGantt chart\n\n");     
    printf("\n--------------------------------------------------------------------\n");         

    
    for (int i = 0; i < n; i++) {
        printf("\t p%d\t||", p[i]);
    }

    printf("\n---------------------------------------------------------------------\n");

  
    }
   

 


