/*
    This code takes the AT and BT for the given processes and performs the 
    Shortest Job First (Non-Preemptive) Algorithm.
    Then it outputs the Entire Table giving all the required times. 
*/
#include<stdio.h>

int main() {
    int pid[100], bt[100], wt[100], tat[100], at[100], ct[100], n,
        temp, pos;
    printf("Enter the number of processes: \n");
    scanf("%d", & n);
    printf("Enter process id of all the processes: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", & pid[i]);
    }
    printf("Enter arrival time of all the processes: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", & at[i]);
    }
    printf("Enter burst time of all the processes: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", & bt[i]);
    }
    for (int i = 0; i < n; i++) {
        pos = i;
        for (int j = i + 1; j < n; j++) {
            if (bt[j] < bt[pos])
                pos = j;
        }
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;
        temp = pid[i];
        pid[i] = pid[pos];
        pid[pos] = temp;
        temp = at[i];
        at[i] = at[pos];
        at[pos] = temp;
    }
    wt[0] = 0;
    for (int i = 1; i < n; i++) {
        wt[i] = 0;
        for (int j = 0; j < i; j++) {
            wt[i] += bt[j];
        }
    }
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
    for (int i = 0; i < n; i++) {
        ct[i] = at[i] + tat[i];
    }
    printf("Table is:\n");
    printf("PID\tAT\tBT\tWT\tAT\tCT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], wt[i],
            tat[i], ct[i]);
    }
    return 0;
}