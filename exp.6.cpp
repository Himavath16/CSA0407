#include <stdio.h>

struct Process {
    int pid;       
    int bt;        
    int rt;        
    int pr;        
    int wt;       
    int tat;       
};

int main() {
    int n, i, time = 0, completed = 0, min_pr;
    struct Process p[20];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time and priority for each process:\n");
    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("P%d (BT Priority): ", p[i].pid);
        scanf("%d %d", &p[i].bt, &p[i].pr);
        p[i].rt = p[i].bt;   
        p[i].wt = 0;
        p[i].tat = 0;
    }

    
    while (completed < n) {
        int idx = -1;
        min_pr = 9999;

        
        for (i = 0; i < n; i++) {
            if (p[i].rt > 0 && p[i].pr < min_pr) {
                min_pr = p[i].pr;
                idx = i;
            }
        }

        if (idx != -1) {
            p[idx].rt--;  
            time++;

            
            if (p[idx].rt == 0) {
                completed++;
                p[idx].tat = time;                 
                p[idx].wt = p[idx].tat - p[idx].bt;
            }
        } else {
            time++;  
        }
    }

    float avg_wt = 0, avg_tat = 0;

    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n",
               p[i].pid, p[i].bt, p[i].pr, p[i].wt, p[i].tat);
        avg_wt += p[i].wt;
        avg_tat += p[i].tat;
    }

    avg_wt /= n;
    avg_tat /= n;

    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);

    return 0;
}

