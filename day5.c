#include <stdio.h>

int main() {
    unsigned int n;
    int ones = 0, zeros = 0, current = 0, max = 0;

    scanf("%u", &n);

    if (n == 0) {
        printf("1s = 0\n0s = 1\nConsecutive 1s = 0");
        return 0;
    }

    while (n) {
        if (n & 1) {
            ones++;
            if (++current > max)
                max = current;
        } else {
            zeros++;
            current = 0;
        }
        n >>= 1;
    }

    printf("1s = %d\n0s = %d\nConsecutive 1s = %d", ones, zeros, max);

    return 0;
}