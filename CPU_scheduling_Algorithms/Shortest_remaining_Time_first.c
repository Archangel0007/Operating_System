/*
    This code takes the AT and BT for the given processes and performs the 
    Shortest Remaining time First (Preemptive) Algorithm.
    Then it outputs the Entire Table giving all the required times. 
*/
#include <stdio.h>
#include <stdbool.h>
int main() {
    int t = 0;
    int pid[100], bt[100], wt[100], tat[100], at[100], ct[100], rt[100], n;
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
        rt[i] = bt[i];
    }

    bool done = false;
    while (!done) {
        int min = -1;
        for (int i = 0; i < n; i++) {
            if (at[i] <= t && rt[i] > 0) {
                if (min == -1 || rt[i] < rt[min]) {
                    min = i;
                }
            }
        }
        if (min == -1) {
            t++;
            continue;
        }
        rt[min]--;
        if (rt[min] == 0) {
            ct[min] = t + 1;
            tat[min] = ct[min] - at[min];
            wt[min] = tat[min] - bt[min];
        }
        t++;
        if (t == ct[min]) {
            min = -1;
        }
        done = true;
        for (int i = 0; i < n; i++) {
            if (rt[i] > 0) {
                done = false;
                break;
            }
        }
    }
    printf("Pid At Bt Wt Tat Ct\n");
    for (int i = 0; i < n; i++) {
        printf("%d %d %d %d %d %d \n", pid[i], at[i], bt[i],
            wt[i], tat[i], ct[i]);
    }
    return 0;
}