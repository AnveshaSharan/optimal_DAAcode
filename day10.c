#include <stdio.h>

void sortedSquares(int arr[], int n) {
    int result[n];

    int left = 0;
    int right = n - 1;
    int pos = n - 1;

    while (left <= right) {
        int leftSquare = arr[left] * arr[left];
        int rightSquare = arr[right] * arr[right];

        if (leftSquare > rightSquare) {
            result[pos] = leftSquare;
            left++;
        } else {
            result[pos] = rightSquare;
            right--;
        }

        pos--;
    }

    // Copy result back to original array
    for (int i = 0; i < n; i++) {
        arr[i] = result[i];
    }
}

int main() {
    int arr[] = {-7, -3, 2, 3, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    sortedSquares(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}