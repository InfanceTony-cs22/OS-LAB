#include <stdio.h>

void cscanDiskScheduling(int requests[], int n, int head, int max) {
    int seek_sequence[n+1], distance, seek_count = 0, cur_track;
    int i;

    // Sorting requests
    for (i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (requests[i] > requests[j]) {
                int temp = requests[i];
                requests[i] = requests[j];
                requests[j] = temp;
            }
        }
    }

    // Accessing requests on right of head
    for (i = 0; i < n; i++) {
        if (requests[i] >= head) {
            cur_track = requests[i];
            seek_sequence[seek_count++] = cur_track;
            distance = abs(cur_track - head);
            seek_count += distance;
            head = cur_track;
            break;
        }
    }

    // Wrapping around
    if (i == n) {
        head = 0;
        seek_count += max;
    }

    // Accessing requests on left of head
    for (i = 0; i < n; i++) {
        if (requests[i] < head) {
            cur_track = requests[i];
            seek_sequence[seek_count++] = cur_track;
            distance = abs(cur_track - head);
            seek_count += distance;
            head = cur_track;
        }
    }

    printf("Seek Sequence: ");
    for (i = 0; i < seek_count; i++)
        printf("%d ", seek_sequence[i]);
    printf("\nTotal Seek Operations = %d\n", seek_count);
}

int main() {
    int requests[] = {55, 58, 39, 18, 91, 72, 61, 2};
    int n = sizeof(requests) / sizeof(requests[0]);
    int head = 50;
    int max = 200; // Assume disk has 200 cylinders

    cscanDiskScheduling(requests, n, head, max);
    return 0;
}
