#include <stdio.h>

void implementWorstFit(int blockSize[], int blocks, int processSize[], int processes) {
        int allocation[processes];
        int occupied[blocks];
        int totalExternalFragmentation = 0;
        for (int i = 0; i < processes; i++) {
            allocation[i] = -1;
        }
        for (int i = 0; i < blocks; i++) {
            occupied[i] = 0;
        }
        for (int i = 0; i < processes; i++) {
            int indexPlaced = -1;
            for (int j = 0; j < blocks; j++) {
                if (blockSize[j] >= processSize[i] && !occupied[j]) {
                    if (indexPlaced == -1)
                        indexPlaced = j;
                    else if (blockSize[j] > blockSize[indexPlaced])
                        indexPlaced = j;
                }
            }
            if (indexPlaced != -1) {
                allocation[i] = indexPlaced;
                occupied[indexPlaced] = 1;
            } else {
                totalExternalFragmentation += processSize[i];
            }
        }
        printf("21BCE1351 S.Navaneetha
            Krishnan\ nProcess No.\tProcess Size\ tBlock no.\tInternal Fragmentation\ n ");
            for (int i = 0; i < processes; i++) {
                printf("%d \t\t\t %d \t\t\t", i + 1, processSize[i]);
                if (allocation[i] != -1) {
                    int internalFragmentation = blockSize[allocation[i]] - processSize[i];
                    printf("%d \t\t\t%d\n", allocation[i] + 1, internalFragmentation);
                } else
                    printf("Not Allocated\n");
            }
            printf("Total External Fragmentation: %d\n", totalExternalFragmentation);
        }
        int main() {
            int blockSize[] = {
                100,
                50,
                30,
                120,
                35
            };
            int processSize[] = {
                40,
                10,
                30,
                60
            };
            int blocks = sizeof(blockSize) / sizeof(blockSize[0]);
            int processes = sizeof(processSize) / sizeof(processSize[0]);
            implementWorstFit(blockSize, blocks, processSize, processes);
            return 0;
        }
