#include <stdio.h>
#include <stdlib.h>

struct process {
    int process_id;
    char process_name[20];
    float process_arrival_time;
    float process_completion_time;
    float process_execution_time;
};

void process_details(struct process *p) {
    printf("Enter the process ID: ");
    scanf("%d", &p->process_id);

    printf("Enter the process name: ");
    scanf("%s", p->process_name);

    printf("Enter the process arrival time: ");
    scanf("%f", &p->process_arrival_time);

    printf("Enter the process completion time: ");
    scanf("%f", &p->process_completion_time);

    p->process_execution_time = p->process_completion_time - p->process_arrival_time;
}

void display_details(struct process p) {
    printf("\nProcess ID: %d\n", p.process_id);
    printf("Process Name: %s\n", p.process_name);
    printf("Process Arrival Time: %f\n", p.process_arrival_time);
    printf("Process Completion Time: %f\n", p.process_completion_time);
    printf("Process Execution Time: %f\n", p.process_execution_time);
}

void search_process(struct process processes[], int n, int search_id) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (processes[i].process_id == search_id) {
            display_details(processes[i]);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Process with ID %d not found.\n", search_id);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process processes[n];

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Display all process details\n");
        printf("2. Search for a process by process ID\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                for (int i = 0; i < n; i++) {
                    printf("Enter details for process %d:\n", i + 1);
                    process_details(&processes[i]);
                }

                printf("\nProcess Details:\n");
                for (int i = 0; i < n; i++) {
                    printf("\nDetails of Process %d:\n", i + 1);
                    display_details(processes[i]);
                }
                break;

            case 2:

                    {


                    int search_id;
                    printf("Enter the process ID to search for: ");
                    scanf("%d", &search_id);
                    search_process(processes, n, search_id);
                    }
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
