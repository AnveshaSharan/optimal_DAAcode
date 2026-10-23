#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int lower = 0, upper = 0, digit = 0, special = 0;

    printf("Enter password: ");
    scanf("%s", s);

    int n = strlen(s);

    for (int i = 0; i < n; i++) {

        // Check lowercase letter (can be anywhere)
        if (s[i] >= 'a' && s[i] <= 'z') {
            lower = 1;
        }

        // Uppercase, digit and special character
        // must be strictly inside
        if (i > 0 && i < n - 1) {

            if (s[i] >= 'A' && s[i] <= 'Z') {
                upper = 1;
            }

            if (s[i] >= '0' && s[i] <= '9') {
                digit = 1;
            }

            if (s[i] == '@' || s[i] == '#' ||
                s[i] == '%' || s[i] == '&' ||
                s[i] == '?') {
                special = 1;
            }
        }
    }

    // Check all conditions
    if (n >= 10 && lower && upper && digit && special) {
        printf("Secure Password");
    }
    else {
        printf("Not Secure Password");
    }

    return 0;
}