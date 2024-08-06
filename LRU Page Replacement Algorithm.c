#include <stdio.h>

#define FRAME_SIZE 3

void lruPageReplacement(int pages[], int n) {
    int frame[FRAME_SIZE];
    for (int i = 0; i < FRAME_SIZE; i++)
        frame[i] = -1;

    int page_faults = 0, pos, found, count[FRAME_SIZE] = {0};

    for (int i = 0; i < n; i++) {
        found = 0;
        for (int j = 0; j < FRAME_SIZE; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                count[j]++;
                break;
            }
        }

        if (found == 0) {
            pos = 0;
            for (int j = 1; j < FRAME_SIZE; j++) {
                if (count[j] < count[pos])
                    pos = j;
            }
            frame[pos] = pages[i];
            count[pos] = 1;
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

    lruPageReplacement(pages, n);
    return 0;
}
