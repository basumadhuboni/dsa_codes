#include <stdio.h>
#include <stdlib.h>

int s = 0;

struct info {
    int id;
    int p;
    char name[10];
};

struct info arr[100];

void swap(struct info* a, struct info* b) {
    struct info temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(struct info arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].p < arr[smallest].p)
        smallest = left;

    if (right < n && arr[right].p < arr[smallest].p)
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void buildMinHeap(struct info arr[], int n) {
    int i;
    for (i = (n / 2) - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }
}

void deleteNode(struct info arr[], int* s) {
    printf("%d %d %s\n", arr[0].id, arr[0].p, arr[0].name);
    swap(&arr[0], &arr[*s - 1]);
    (*s)--;
    minHeapify(arr, *s, 0);
}

void updatep(struct info arr[], int n, int p2) {
    int newp, i;
    for (i = 0; i < n; i++) {
        if (arr[i].id == p2) {
            printf("Enter the new priority: ");
            scanf("%d", &newp);
            arr[i].p = newp;
            break; // No need to continue searching
        }
    }
    buildMinHeap(arr, s);
}

void clearheap(struct info arr[], int m) {
    s = 0;
}

void printArray(struct info arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d %d %s ", arr[i].id, arr[i].p, arr[i].name);
    }
    printf("\n");
}

int main() {
    int i, ch, k = 0, p1;
    char c, t = 'y';

    while (t == 'y') {
        printf("1 for adding, 2 for deletion, 3 for display, 4 for number of patients in queue, 5 for update, 6 for clear\n");
        scanf("%d", &ch);

        if (ch == 1) {
            for (i = 0; i < 100; i++) {
                s++;
                printf("Enter patient id: ");
                scanf("%d", &arr[i].id);
                printf("Enter patient priority: ");
                scanf("%d", &arr[i].p);
                printf("Enter patient name: ");
                scanf("%s", arr[i].name);
                printf("Do you want to enter more patients? (y/n): ");
                scanf(" %c", &c);
                if (c == 'n') {
                    break;
                }
            }
            buildMinHeap(arr, s);
        } else if (ch == 2) {
            deleteNode(arr, &s);
        } else if (ch == 3) {
            printf("Array: ");
            printArray(arr, s);
        } else if (ch == 4) {
            printf("The number of patients waiting is %d\n", s);
        } else if (ch == 5) {
            printf("Enter the id of the patient whose priority needs to be updated: ");
            scanf("%d", &p1);
            updatep(arr, s, p1);
        } else if (ch == 6) {
            clearheap(arr, s);
        }

        printf("Do you want to perform more operations? (y/n): ");
        scanf(" %c", &t);
    }

    return 0;
}
