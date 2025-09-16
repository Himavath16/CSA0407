#include <stdio.h>

struct Process {
    int pid;        
    int burst;      
    int remaining;  
    int wait;     
    int turn;       
};

int main() {
    int n, i, tq, time = 0, done;
    struct Process p[20];

    
    printf("Enter number of processes: ");
    scanf("%d", &n);

  
    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Burst Time for Process %d: ", p[i].pid);
        scanf("%d", &p[i].burst);
        p[i].remaining = p[i].burst;
        p[i].wait = 0;
        p[i].turn = 0;
    }

    
    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    printf("\nGantt Chart: ");
    
    
    do {
        done = 1;  
        for (i = 0; i < n; i++) {
            if (p[i].remaining > 0) {
                done = 0; 
                if (p[i].remaining > tq) {
                    
                    printf(" | P%d", p[i].pid);
                    time += tq;
                    p[i].remaining -= tq;
                } else {
                    
                    printf(" | P%d", p[i].pid);
                    time += p[i].remaining;
                    p[i].wait = time - p[i].burst;
                    p[i].turn = time;
                    p[i].remaining = 0;
                }
            }
        }
    } while (!done);

    printf(" |\n");

    
    float avg_wait = 0, avg_turn = 0;
    for (i = 0; i < n; i++) {
        avg_wait += p[i].wait;
        avg_turn += p[i].turn;
    }
    avg_wait /= n;
    avg_turn /= n;

    
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst, p[i].wait, p[i].turn);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wait);
    printf("\nAverage Turnaround Time = %.2f\n", avg_turn);

    return 0;
}

