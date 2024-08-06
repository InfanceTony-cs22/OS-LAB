#include <stdio.h>

void findavgTime(int processes[], int n, int bt[], int priority[]) {
    int wt[n], tat[n];
    float total_wt = 0, total_tat = 0;

    // Sorting based on priority (lowest number indicates highest priority)
    int sorted_bt[n], sorted_processes[n], sorted_priority[n];
    for (int i = 0; i < n; i++) {
        sorted_bt[i] = bt[i];
        sorted_processes[i] = processes[i];
        sorted_priority[i] = priority[i];
    }
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (sorted_priority[i] > sorted_priority[j]) {
                int temp_bt = sorted_bt[i];
                sorted_bt[i] = sorted_bt[j];
                sorted_bt[j] = temp_bt;

                int temp_process = sorted_processes[i];
                sorted_processes[i] = sorted_processes[j];
                sorted_processes[j] = temp_process;

                int temp_priority = sorted_priority[i];
                sorted_priority[i] = sorted_priority[j];
                sorted_priority[j] = temp_priority;
            }
        }
    }

    wt[0] = 0;
    for (int i = 1; i < n; i++) {
        wt[i] = 0;
        for (int j = 0; j < i; j++)
            wt[i] += sorted_bt[j];
    }

    for (int i = 0; i < n; i++) {
        tat[i] = sorted_bt[i] + wt[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("Process ID\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", sorted_processes[i], sorted_bt[i], sorted_priority[i], wt[i], tat[i]);

    printf("Average Waiting Time = %.2f\n", total_wt / n);
    printf("Average Turnaround Time = %.2f\n", total_tat / n);
}

int main() {
    int processes[] = {1, 2, 3};
    int bt[] = {10, 5, 8};
    int priority[] = {2, 1, 3};
    int n = sizeof(processes) / sizeof(processes[0]);

    findavgTime(processes, n, bt, priority);
    return 0;
}
