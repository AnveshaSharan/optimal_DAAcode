#include <stdio.h>

int main() {
    int n, digit;
    int present[10] = {0};

    printf("Enter a number: ");
    scanf("%d", &n);

    while (n > 0) {
        digit = n % 10;
        present[digit] = 1;
        n = n / 10;
    }

    for (int i = 0; i < 10; i++) {
        if (present[i] == 0) {
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}