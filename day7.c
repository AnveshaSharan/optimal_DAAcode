#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    int left = 0, right = n - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        // Make mid even
        if (mid % 2 != 0)
            mid--;

        if (nums[mid] == nums[mid + 1])
            left = mid + 2;
        else
            right = mid;
    }

    printf("Single element: %d", nums[left]);

    return 0;
}