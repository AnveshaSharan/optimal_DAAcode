#include <stdio.h>

int main() {
    int arr[] = {2, 7, 11, 15};
    int target = 9;
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                printf("[%d, %d]", i, j);
                return 0;
            }
        }
    }

    return 0;
}