#include<stdio.h>

int linearSearch(int items[], int length, int searchItem) {
    int i, j;
    for(i = 0; i < length; i++) {
        if(items[i] == searchItem) return i; // found
    }
    return -1; // not found
}

int binarySearch(int items[], int length, int searchItem) {
    int lowerIndex = 0;
    int upperIndex = length;
    int midIndex;

    while(lowerIndex <= upperIndex) {
        midIndex = (lowerIndex + upperIndex) / 2;
        if(items[midIndex] == searchItem) 
            return midIndex;
        else if(searchItem < midIndex) {
            upperIndex = midIndex;
        } else {
            lowerIndex = midIndex;
        }
    }

    return -1;
}

int insertionSort(int items[], int length) {
    int i, j, tmp;
    for(i = 1; i < length; i++) {
        j = i - 1;

        while(j > 0 && items[j] > items[i]) j--;
        tmp = items[i];
        items[i] = items[j];
        items[j] = tmp;
    }
}

void printArray(int items[], int length) {
    int i = 0;
    while(i < length) {
        printf("%d ", items[i++]);
    }
    printf("\n");
}

int main() {
    int items[] = {122, 23, 331, 4, 584, 288};
    int length = 6;
    int searchItem = 88;

    // int foundAt = linearSearch(items, length, searchItem);
    int foundAt = binarySearch(items, length, searchItem);

    if(foundAt != -1)
        printf("%d found at index[%d]\n", searchItem, foundAt);
    else 
        printf("%d not found in array\n", searchItem);

    return 0;
}