#include <stdio.h>

int quick_count = 0;
int selection_count = 0;
int bubble_count = 0;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Quick sort
int partition(int arr[], int lb, int ub) {
    int pivot = arr[ub];
    int i = lb - 1;

    for (int j = lb; j <= ub - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
            quick_count++;
        }
    }

    swap(&arr[i + 1], &arr[ub]);
    quick_count++;
    return (i + 1);
}

void quicksort(int arr[], int lb, int ub) {
    if (lb < ub) {
        int part = partition(arr, lb, ub);
        quicksort(arr, lb, part - 1);
        quicksort(arr, part + 1, ub);
    }
}

// Selection sort
void selection(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        if (min != i) {
            swap(&arr[i], &arr[min]);
            selection_count++;
        }
    }
}

// Bubble sort
void bubble(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                bubble_count++;
            }
        }
    }
}

int main() {
    int arr[] = {10, 2, 3, 1, 56, 48, 24, 79, 11, 90, 35, 23, 36, 78};
    int n = sizeof(arr) / sizeof(arr[0]);

    int quick_arr[n], selection_arr[n], bubble_arr[n];
    for (int i = 0; i < n; i++) {
        quick_arr[i] = arr[i];
        selection_arr[i] = arr[i];
        bubble_arr[i] = arr[i];
    }
    // copying the array into three diffrent arrays because after each sort the array will get sorted
    quicksort(quick_arr, 0, n - 1);
    selection(selection_arr, n);
    bubble(bubble_arr, n);

    printf("Number of swaps in Quick sort: %d\n", quick_count);
    printf("Number of swaps in Selection sort: %d\n", selection_count);
    printf("Number of swaps in Bubble sort: %d\n", bubble_count);

    if (quick_count <= selection_count && quick_count <= bubble_count) {
        printf("Quick sort needs the minimum number of swaps.\n");
    } else if (selection_count <= quick_count && selection_count <= bubble_count) {
        printf("Selection sort needs the minimum number of swaps.\n");
    } else {
        printf("Bubble sort needs the minimum number of swaps.\n");
    }

    return 0;
}