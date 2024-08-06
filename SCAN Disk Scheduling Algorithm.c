#include <stdio.h>

void scanDiskScheduling(int requests[], int n, int head, int direction) {
    int seek_sequence[n+1], distance, seek_count = 0, cur_track;
    int max = 200; // Assume disk has 200 cylinders

    // Sorting requests
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (requests[i] > requests[j]) {
                int temp = requests[i];
                requests[i] = requests[j];
                requests[j] = temp;
            }
        }
    }

    int i;
    if (direction == 0) { // Left direction
        for (i = 0; i < n; i++) {
            if (requests[i] > head)
                break;
        }

        // Accessing requests on left of head
        for (int j = i-1; j >= 0; j--) {
            cur_track = requests[j];
            seek_sequence[seek_count++] = cur_track;
            distance = abs(cur_track - head);
            seek_count += distance;
            head = cur_track;
        }

        // Accessing requests on right of head
        for (int j = i; j < n; j++) {
            cur_track = requests[j];
            seek_sequence[seek_count++] = cur_track;
            distance = abs(cur_track - head);
            seek_count += distance;
            head = cur_track;
        }
    } else { // Right direction
        for (i = 0; i < n; i++) {
            if (requests[i] > head)
                break;
        }

        // Accessing requests on right of head
        for (int j = i; j < n; j++) {
            cur_track = requests[j];
            seek_sequence[seek_count++] = cur_track;
            distance = abs(cur_track - head);
            seek_count += distance;
            head = cur_track;
        }

        // Accessing requests on left of head
        for (int j = i-1; j >= 0; j--) {
            cur_track = requests[j];
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
    int direction = 1; // 0 for left, 1 for right

    scanDiskScheduling(requests, n, head, direction);
    return 0;
}
