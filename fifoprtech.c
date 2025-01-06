#include <stdio.h>

void FCFS(int pages[], int n, int capacity) {
    int frames[capacity];
    int faults = 0, index = 0;
    int i, j, found;

    for (i = 0; i < capacity; i++) {
        frames[i] = -1; // Initialize all frames to -1
    }

    for (i = 0; i < n; i++) {
        found = 0;

        // Check if the page is already in a frame
        for (j = 0; j < capacity; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            // Page fault occurs
            faults++;
            frames[index] = pages[i]; // Replace the page at the current index
            index = (index + 1) % capacity; // Update index in a circular manner
        }

        // Print the current frame status
        printf("Step %d: ", i + 1);
        for (j = 0; j < capacity; j++) {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("Total Page Faults: %d\n", faults);
}

int main() {
    int n, capacity, i;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter the pages: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter the frame capacity: ");
    scanf("%d", &capacity);

    FCFS(pages, n, capacity);

    return 0;
}