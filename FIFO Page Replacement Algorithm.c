#include <stdio.h>

#define FRAME_SIZE 3

void fifoPageReplacement(int pages[], int n) {
    int frame[FRAME_SIZE];
    for (int i = 0; i < FRAME_SIZE; i++)
        frame[i] = -1;

    int page_faults = 0, next = 0;

    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < FRAME_SIZE; j++) {
            if (frame[j] == pages[i]) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            frame[next] = pages[i];
            next = (next + 1) % FRAME_SIZE;
            page_faults++;
        }

        printf("Page frames: ");
        for (int j = 0; j < FRAME_SIZE; j++)
            printf("%d ", frame[j]);
        printf("\n");
    }
    printf("Total Page Faults = %d\n", page_faults);
}

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3};
    int n = sizeof(pages) / sizeof(pages[0]);

    fifoPageReplacement(pages, n);
    return 0;
}
