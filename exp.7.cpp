#include <stdio.h>

struct Process {
    int pid;        
    int burst;      
    int wait;       
    int turn;       
};

int main() {
    int n, i, j;
    struct Process p[20], temp;
    float avg_wait = 0, avg_turn = 0;

    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    
    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Burst Time for Process %d: ", p[i].pid);
        scanf("%d", &p[i].burst);
    }

    
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].burst > p[j].burst) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    
    p[0].wait = 0;
    p[0].turn = p[0].burst;

    
    for (i = 1; i < n; i++) {
        p[i].wait = p[i - 1].wait + p[i - 1].burst;
        p[i].turn = p[i].wait + p[i].burst;
    }

   
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

