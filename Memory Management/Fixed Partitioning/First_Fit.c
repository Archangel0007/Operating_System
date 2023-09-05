#include <stdio.h>
int main() {
        int b, p;
        scanf("%d", & b);
        scanf("%d", & p);
        int blocks[b], processes[p];
        for (int i = 0; i < b; i++) {
            scanf("%d", & blocks[i]);
        }
        for (int i = 0; i < p; i++) {
            scanf("%d", & processes[i]);
        }
        int internal_fragmentation = 0, alloted[b], process_allocated[p];
        for (int i = 0; i < b; i++) {
            alloted[i] = 0;
        }
        for (int i = 0; i < p; i++) {
            process_allocated[i] = 0;
        }
        printf("21BCE1351 S.Navaneetha Krishnan\nFile No\tFile Size\tBlock
            No\ tBlock Size\ tIFragment\ n ");
            for (int i = 0; i < p; i++) {
                for (int j = 0; j < b; j++) {
                    if (alloted[j] == 0 && processes[i] <= blocks[j]) {
                        alloted[j] = 1;
                        process_allocated[i] = 1;
                        internal_fragmentation += blocks[j] - processes[i];
                        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d", i, processes[i], j, blocks[j],
                            blocks[j] - processes[i]);
                        break;
                    }
                }
                printf("\n");
            }
            printf("internal_fragmentation=%d\n", internal_fragmentation); int flag = 0;
            for (int i = 0; i < p; i++) {
                if (process_allocated[i] == 0) {
                    printf("External_Fragmentation=%d", processes[i]);
                    flag++;
                }
            }
            if (flag == 0) {
                printf("External_Fragmentation=0");
            }
        }
