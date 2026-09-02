#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int m, int n, int* returnSize) {
    *returnSize = m * n;
    int* result = (int*)malloc(sizeof(int) * (*returnSize));
    if (!result) return NULL;

    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;
    int idx = 0;

    while (top <= bottom && left <= right) {
        // left -> right along top row
        for (int col = left; col <= right; col++)
            result[idx++] = matrix[top][col];
        top++;

        // top -> bottom along right column
        for (int row = top; row <= bottom; row++)
            result[idx++] = matrix[row][right];
        right--;

        // right -> left along bottom row
        if (top <= bottom) {
            for (int col = right; col >= left; col--)
                result[idx++] = matrix[bottom][col];
            bottom--;
        }

        // bottom -> top along left column
        if (left <= right) {
            for (int row = bottom; row >= top; row--)
                result[idx++] = matrix[row][left];
            left++;
        }
    }

    return result;
}

// ---- Test driver ----
int main(void) {
    int m = 3, n = 4;
    int data[3][4] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12}
    };

    // Build array of row pointers (matches int** signature)
    int* matrix[3];
    for (int i = 0; i < m; i++) matrix[i] = data[i];

    int returnSize;
    int* result = spiralOrder(matrix, m, n, &returnSize);

    for (int i = 0; i < returnSize; i++)
        printf("%d%s", result[i], (i == returnSize - 1) ? "\n" : ", ");

    free(result);
    return 0;
}