/* Q22: Move all zeroes to the end while preserving nonzero order
   Simple method: O(n) time, O(n) auxiliary space.
   Optimal in-place method: O(n) time, O(1) auxiliary space.
*/
#include <stdio.h>

void moveZeroesSimple(const int arr[], int n, int result[]) {
    int pos = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] != 0) result[pos++] = arr[i];
    while (pos < n) result[pos++] = 0;
}

void moveZeroesOptimal(int arr[], int n) {
    int pos = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] != 0) arr[pos++] = arr[i];
    while (pos < n) arr[pos++] = 0;
}

void printArray(const int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\\n");
}

int main(void) {
    int arr[] = {0, 1, 0, 3, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result[5];
    int optimal[] = {0, 1, 0, 3, 12};

    moveZeroesSimple(arr, n, result);
    printf("Simple method: ");
    printArray(result, n);

    moveZeroesOptimal(optimal, n);
    printf("Optimal method: ");
    printArray(optimal, n);
    return 0;
}
