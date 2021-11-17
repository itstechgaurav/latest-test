#include<stdio.h>

void printArray(int[], int);
void printArrayFrom(int items[], int lower, int length);

void insertionSort(int items[], int length) {
    int i, j, tmp;
    for(i = 1; i < length; i++) {
        j = i - 1;
        tmp = items[i];
        while(j >= 0 && items[j] > tmp) {
            items[j + 1] = items[j];
            j--;
        }
        items[j + 1] = tmp;
    }
}

void swap(int items[], int i, int j) {
    int tmp = items[i];
    items[i] = items[j];
    items[j] = tmp;
}

int partition(int items[], int l, int h) {
    int pivot = items[l];
    int i = l, j = h, tmp;

    while(i < j) {
        do { i++; } while(items[i] <= pivot);
        do { j--; } while(items[j] > pivot);
        if(i < j) {
            swap(items, i, j);
        }
    }
    swap(items, l, j);
    return j;
}

void quickSort(int items[], int lower, int max) {
    if(lower < max) {
        int j = partition(items, lower, max);
        quickSort(items, lower, j);
        quickSort(items, j + 1, max);
    }
}

void merge(int items[], int lower, int mid, int max) {
    int i = lower, j = mid + 1;

    while(i <= max && j <= max) {
        if(items[i] > items[j]) {
            swap(items, i, j);
            i++;
        } else if(items[i] < items[j]) {
            i++;
        } else {
            j++;
        }
    }
}

void mergeSort(int items[], int lower, int max) {
    if(lower < max) {
        int mid = (lower + max) / 2;
        mergeSort(items, lower, mid); // break into left half
        mergeSort(items, mid + 1, max); // break into right half
        merge(items, lower, mid, max); // at last merge them
    }
}

void printArray(int items[], int length) {
    int i = 0;
    while(i < length) {
        printf("%d ", items[i++]);
    }
    printf("\n");
}

void printArrayFrom(int items[], int lower, int length) {
    int i = lower;
    while(i < length) {
        printf("%d ", items[i++]);
    }
    printf("\n");
}

int main() {
    int items[] = {122, 23, 331, 4, 584, 288};
    // int items[] = {2, 4, 6, 3, 5, 7};
    int length = 6;

    /// sorting messages
    printf("Before sorting: ");
    printArray(items, length);
    mergeSort(items, 0, length - 1);
    printf("After sorting: ");
    printArray(items, length);

    return 0;
}