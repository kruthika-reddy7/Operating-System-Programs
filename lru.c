Write C programs to simulate Page replacement policies                                                                                             LRU                                                                                                                                                                              #include <stdio.h>

void LRU(int pages[], int n, int capacity) {
    int frames[capacity];
    int counter[capacity];
    int time = 0, faults = 0, found, i, j, least, pos;

    for (i = 0; i < capacity; i++) {
        frames[i] = -1;
        counter[i] = 0;
    }

    for (i = 0; i < n; i++) {
        found = 0;

        // Check if the page is already in a frame
        for (j = 0; j < capacity; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                counter[j] = ++time;  // Update the usage time
                break;
            }
        }

        if (!found) {
            faults++;

            // Find the least recently used page
            least = counter[0];
            pos = 0;
            for (j = 1; j < capacity; j++) {
                if (counter[j] < least) {
                    least = counter[j];
                    pos = j;
                }
            }

            // Replace the least recently used page
            frames[pos] = pages[i];
            counter[pos] = ++time;
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

    LRU(pages, n, capacity);

    return 0;
}