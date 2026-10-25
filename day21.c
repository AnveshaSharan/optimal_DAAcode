/* Q21: Find the kth largest element using three methods
   1. Merge sort descending: O(n log n) time, O(n) auxiliary space.
   2. Min-heap of size k: O(n log k) time, O(k) auxiliary space.
   3. Quickselect: average O(n), worst O(n^2) time, O(1) auxiliary space.
   Assumes k is 1..n. Duplicate values count as separate array elements.
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void mergeDesc(int a[], int tmp[], int l, int m, int r) {
    int i = l, j = m + 1, p = l;
    while (i <= m && j <= r)
        tmp[p++] = (a[i] >= a[j]) ? a[i++] : a[j++];
    while (i <= m) tmp[p++] = a[i++];
    while (j <= r) tmp[p++] = a[j++];
    for (i = l; i <= r; i++) a[i] = tmp[i];
}
void mergeSortDescRec(int a[], int tmp[], int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSortDescRec(a, tmp, l, m);
    mergeSortDescRec(a, tmp, m + 1, r);
    mergeDesc(a, tmp, l, m, r);
}
int kthBySorting(int a[], int n, int k) {
    if (k < 1 || k > n) return INT_MIN;
    int *tmp = malloc((size_t)n * sizeof(int));
    if (!tmp) { perror("malloc"); exit(EXIT_FAILURE); }
    mergeSortDescRec(a, tmp, 0, n - 1);
    free(tmp);
    return a[k - 1];
}

void heapPush(int h[], int *size, int value) {
    int i = (*size)++;
    h[i] = value;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h[p] <= h[i]) break;
        int t = h[p]; h[p] = h[i]; h[i] = t;
        i = p;
    }
}
void heapReplaceRoot(int h[], int size, int value) {
    h[0] = value;
    int i = 0;
    while (1) {
        int l = 2 * i + 1, r = 2 * i + 2, smallest = i;
        if (l < size && h[l] < h[smallest]) smallest = l;
        if (r < size && h[r] < h[smallest]) smallest = r;
        if (smallest == i) break;
        int t = h[i]; h[i] = h[smallest]; h[smallest] = t;
        i = smallest;
    }
}
int kthByMinHeap(const int a[], int n, int k) {
    if (k < 1 || k > n) return INT_MIN;
    int *h = malloc((size_t)k * sizeof(int));
    if (!h) { perror("malloc"); exit(EXIT_FAILURE); }
    int size = 0;
    for (int i = 0; i < n; i++) {
        if (size < k) heapPush(h, &size, a[i]);
        else if (a[i] > h[0]) heapReplaceRoot(h, size, a[i]);
    }
    int answer = h[0];
    free(h);
    return answer;
}

void swapInt(int *a, int *b) { int t = *a; *a = *b; *b = t; }
int partitionAsc(int a[], int low, int high) {
    int pivot = a[high], i = low;
    for (int j = low; j < high; j++)
        if (a[j] <= pivot) swapInt(&a[i++], &a[j]);
    swapInt(&a[i], &a[high]);
    return i;
}
int kthByQuickselect(int a[], int n, int k) {
    if (k < 1 || k > n) return INT_MIN;
    int target = n - k, low = 0, high = n - 1;
    while (low <= high) {
        int p = partitionAsc(a, low, high);
        if (p == target) return a[p];
        if (p < target) low = p + 1;
        else high = p - 1;
    }
    return INT_MIN;
}

int main(void) {
    int a[] = {3, 2, 1, 5, 6, 4};
    int b[] = {3, 2, 1, 5, 6, 4};
    int c[] = {3, 2, 1, 5, 6, 4};
    int n = sizeof(a) / sizeof(a[0]), k = 2;
    printf("Using sorting: %d\\n", kthBySorting(a, n, k));
    printf("Using min-heap: %d\\n", kthByMinHeap(b, n, k));
    printf("Using Quickselect: %d\\n", kthByQuickselect(c, n, k));
    return 0;
}
