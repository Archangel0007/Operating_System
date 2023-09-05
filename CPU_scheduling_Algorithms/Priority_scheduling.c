#include <stdio.h>

// Function to swap two integers using pointers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n;
    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    // Arrays for burst time (b), priority (p), and process id (index)
    int b[n], p[n], index[n];

    // Input burst time and priority for each process
    for (int i = 0; i < n; i++)
    {
        printf("Enter Burst Time and Priority Value for Process %d: ", i + 1);
        scanf("%d %d", &b[i], &p[i]);
        index[i] = i + 1;
    }

    // Sort processes by priority (highest priority first)
    for (int i = 0; i < n; i++)
    {
        int highest_priority = p[i];
        int highest_priority_index = i;

        // Finding the process with the highest priority
        for (int j = i; j < n; j++)
        {
            if (p[j] > highest_priority)
            {
                highest_priority = p[j];
                highest_priority_index = j;
            }
        }

        // Swap processes based on priority
        swap(&p[i], &p[highest_priority_index]);
        swap(&b[i], &b[highest_priority_index]);
        swap(&index[i], &index[highest_priority_index]);
    }

    // Initialize time
    int time = 0;

    // Print the order of process execution
    printf("Order of Process Execution is\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d is executed from %d to %d\n", index[i], time, time + b[i]);
        time += b[i];
    }
    printf("\n");

    // Print process information (Process Id, Burst Time, Wait Time, Turnaround Time)
    printf("Process Id     Burst Time   Wait Time    Turnaround Time\n");
    int total_wait_time = 0;
    for (int i = 0; i < n; i++)
    {
        printf("P%d          %d          %d          %d\n", index[i], b[i], total_wait_time, total_wait_time + b[i]);
        total_wait_time += b[i];
    }

    return 0;
}
