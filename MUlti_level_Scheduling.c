#include <stdio.h>

#define MAX 10

typedef struct {
    int id, arrival_time, burst_time, waiting_time, turnaround_time, completion_time;
} Process;

void calculateTimes(Process queue[], int n) {
    int time = 0;
    for (int i = 0; i < n; i++) {
        if (time < queue[i].arrival_time)
            time = queue[i].arrival_time;
        queue[i].waiting_time = time - queue[i].arrival_time;
        queue[i].turnaround_time = queue[i].waiting_time + queue[i].burst_time;
        queue[i].completion_time = time + queue[i].burst_time;
        time += queue[i].burst_time;
    }
}

void printResults(Process queue[], int n, const char *queueName) {
    printf("\n%s:\n", queueName);
    printf("ID\tAT\tBT\tCT\tTAT\tWT\n");
    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", queue[i].id, queue[i].arrival_time, queue[i].burst_time, queue[i].completion_time, queue[i].turnaround_time, queue[i].waiting_time);
        total_wt += queue[i].waiting_time;
        total_tat += queue[i].turnaround_time;
    }
    printf("Average WT: %.2f, Average TAT: %.2f\n", (float)total_wt / n, (float)total_tat / n);
}

int main() {
    Process q1[MAX], q2[MAX];
    int n1, n2;

    printf("Enter number of system processes (q1): ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        printf("Enter Process ID, Arrival Time, Burst Time for system process %d: ", i + 1);
        scanf("%d %d %d", &q1[i].id, &q1[i].arrival_time, &q1[i].burst_time);
    }

    printf("Enter number of user processes (q2): ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        printf("Enter Process ID, Arrival Time, Burst Time for user process %d: ", i + 1);
        scanf("%d %d %d", &q2[i].id, &q2[i].arrival_time, &q2[i].burst_time);
    }

    calculateTimes(q1, n1);
    calculateTimes(q2, n2);

    printResults(q1, n1, "System Processes (q1)");
    printResults(q2, n2, "User Processes (q2)");

    return 0;
}
