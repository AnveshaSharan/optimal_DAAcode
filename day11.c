// DAY 11 - Squares of a Sorted Array

#include <stdio.h>
#include <stdlib.h>

// Function declaration
int* sorted_squares(int* nums, int numsSize, int* returnSize);

int main() {
    int nums[] = {-7, -3, 2, 3, 11};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int returnSize;

    int* result = sorted_squares(nums, numsSize, &returnSize);

    // Print result
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }

    printf("\n");

    free(result);

    return 0;
}

// Function definition
int* sorted_squares(int* nums, int numsSize, int* returnSize) {

    int left = 0;
    int right = numsSize - 1;

    // Allocate memory for result
    int* result = (int*)malloc(numsSize * sizeof(int));

    // Fill result from right to left
    int idx = numsSize - 1;

    while (left <= right) {

        if (abs(nums[left]) > abs(nums[right])) {

            result[idx] = nums[left] * nums[left];

            left++;
        }
        else {

            result[idx] = nums[right] * nums[right];

            right--;
        }

        idx--;
    }

    *returnSize = numsSize;

    return result;
}