#include <stdio.h>
#include <string.h>

int main() {
    char password[20];

    while (1) {
        printf("Enter password: ");
        scanf("%19s", password);

        if (strcmp(password, "12345") == 0)
            break;

        printf("Incorrect password!\n");
    }

    printf("Login successful!");

    return 0;
}