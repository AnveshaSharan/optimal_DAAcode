#include <stdio.h>

double findMedianSortedArrays(int nums1[], int m, int nums2[], int n) {
    int merged[m + n];

    int i = 0;
    int j = 0;
    int k = 0;

    // Merge both sorted arrays
    while (i < m && j < n) {
        if (nums1[i] < nums2[j]) {
            merged[k++] = nums1[i++];
        } else {
            merged[k++] = nums2[j++];
        }
    }

    // Remaining elements of nums1
    while (i < m) {
        merged[k++] = nums1[i++];
    }

    // Remaining elements of nums2
    while (j < n) {
        merged[k++] = nums2[j++];
    }

    int total = m + n;

    // Odd number of elements
    if (total % 2 != 0) {
        return merged[total / 2];
    }

    // Even number of elements
    return (merged[total / 2 - 1] + merged[total / 2]) / 2.0;
}

int main() {
    int nums1[] = {1, 3};
    int nums2[] = {2};

    int m = 2;
    int n = 1;

    double median = findMedianSortedArrays(nums1, m, nums2, n);

    printf("Median = %.2f\n", median);

    return 0;
}