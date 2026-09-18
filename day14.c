#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    return (x > y) - (x < y);
}

int smallestDifference(int arr1[], int n, int arr2[], int m) {

    qsort(arr1, n, sizeof(int), compare);
    qsort(arr2, m, sizeof(int), compare);

    int i = 0, j = 0;
    int minDiff = INT_MAX;

    while (i < n && j < m) {

        int diff = abs(arr1[i] - arr2[j]);

        if (diff < minDiff)
            minDiff = diff;

        // 0 is the smallest possible difference
        if (minDiff == 0)
            return 0;

        if (arr1[i] < arr2[j])
            i++;
        else
            j++;
    }

    return minDiff;
}

int main() {

    int arr1[] = {1, 3, 15, 11, 2};
    int arr2[] = {23, 127, 235, 19, 8};

    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    printf("Smallest Difference = %d\n",
           smallestDifference(arr1, n, arr2, m));

    return 0;
}