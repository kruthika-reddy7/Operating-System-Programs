/*Write C programs to simulate Pagereplacement policies                                                                                                Optimal replacement*/                                                                                                                                                         #include <stdio.h>

void Optimal(int pages[], int n, int capacity) {
    int frames[capacity];
    int faults = 0, i, j, k, found, replace, farthest, pos;

    for (i = 0; i < capacity; i++) {
        frames[i] = -1;
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
            faults++;

            if (i < capacity) {
                frames[i] = pages[i];
            } else {
                farthest = -1;
                pos = -1;

                // Find the page to replace
                for (j = 0; j < capacity; j++) {
                    replace = 0;
                    for (k = i + 1; k < n; k++) {
                        if (frames[j] == pages[k]) {
                            replace = k;
                            break;
                        }
                    }

                    if (replace == 0) {
                        pos = j;
                        break;
                    }

                    if (replace > farthest) {
                        farthest = replace;
                        pos = j;
                    }
                }

                frames[pos] = pages[i];
            }
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

    Optimal(pages, n, capacity);

    return 0;
}