#include <stdio.h>

#define MAX 100

void firstFit(int blockSize[], int blocks, int processSize[], int processes);
void bestFit(int blockSize[], int blocks, int processSize[], int processes);
void worstFit(int blockSize[], int blocks, int processSize[], int processes);

int main() {
    int blockSize[MAX], processSize[MAX];
    int blocks, processes;

    printf("Enter number of memory blocks: ");
    scanf("%d", &blocks);
    printf("Enter the sizes of the %d memory blocks (space-separated):\n", blocks);
    for (int i = 0; i < blocks; i++)
        scanf("%d", &blockSize[i]);

    printf("Enter number of processes: ");
    scanf("%d", &processes);
    printf("Enter the sizes of the %d processes (space-separated):\n", processes);
    for (int i = 0; i < processes; i++)
        scanf("%d", &processSize[i]);

    printf("\n--- First Fit Allocation ---\n");
    firstFit(blockSize, blocks, processSize, processes);

    printf("\n--- Best Fit Allocation ---\n");
    bestFit(blockSize, blocks, processSize, processes);

    printf("\n--- Worst Fit Allocation ---\n");
    worstFit(blockSize, blocks, processSize, processes);

    return 0;
}

void firstFit(int blockSize[], int blocks, int processSize[], int processes) {
    int allocation[MAX];
    int blockTemp[MAX];

    for (int i = 0; i < blocks; i++)
        blockTemp[i] = blockSize[i];

    for (int i = 0; i < processes; i++) {
        allocation[i] = -1;
        for (int j = 0; j < blocks; j++) {
            if (blockTemp[j] >= processSize[i]) {
                allocation[i] = j;
                blockTemp[j] -= processSize[i];
                break;
            }
        }
    }

    for (int i = 0; i < processes; i++) {
        printf("Process %d (%d KB) -> ", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("Block %d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void bestFit(int blockSize[], int blocks, int processSize[], int processes) {
    int allocation[MAX];
    int blockTemp[MAX];

    for (int i = 0; i < blocks; i++)
        blockTemp[i] = blockSize[i];

    for (int i = 0; i < processes; i++) {
        int bestIdx = -1;
        for (int j = 0; j < blocks; j++) {
            if (blockTemp[j] >= processSize[i]) {
                if (bestIdx == -1 || blockTemp[j] < blockTemp[bestIdx])
                    bestIdx = j;
            }
        }

        allocation[i] = bestIdx;
        if (bestIdx != -1)
            blockTemp[bestIdx] -= processSize[i];
    }

    for (int i = 0; i < processes; i++) {
        printf("Process %d (%d KB) -> ", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("Block %d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void worstFit(int blockSize[], int blocks, int processSize[], int processes) {
    int allocation[MAX];
    int blockTemp[MAX];

    for (int i = 0; i < blocks; i++)
        blockTemp[i] = blockSize[i];

    for (int i = 0; i < processes; i++) {
        int worstIdx = -1;
        for (int j = 0; j < blocks; j++) {
            if (blockTemp[j] >= processSize[i]) {
                if (worstIdx == -1 || blockTemp[j] > blockTemp[worstIdx])
                    worstIdx = j;
            }
        }

        allocation[i] = worstIdx;
        if (worstIdx != -1)
            blockTemp[worstIdx] -= processSize[i];
    }

    for (int i = 0; i < processes; i++) {
        printf("Process %d (%d KB) -> ", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("Block %d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}
