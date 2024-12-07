#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Function to check the strength of the passwordP
void checkPasswordStrength(char password[]) {
    int length = strlen(password);
    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) hasUpper = true;
        if (islower(password[i])) hasLower = true;
        if (isdigit(password[i])) hasDigit = true;
        if (strchr("!@#$%^&*()-_+=<>?", password[i])) hasSpecial = true;
    }

    if (length < 8) {
        printf("Password must be at least 8 characters long.\n");
    }
    if (!hasUpper) {
        printf("Password must contain at least one uppercase letter.\n");
    }
    if (!hasLower) {
        printf("Password must contain at least one lowercase letter.\n");
    }
    if (!hasDigit) {
        printf("Password must contain at least one digit.\n");
    }
    if (!hasSpecial) {
        printf("Password must contain at least one special character (e.g., !, @, #, $).\n");
    }

    if (length >= 8 && hasUpper && hasLower && hasDigit && hasSpecial) {
        printf("Password is strong.\n");
    }
}

int main() {
    char password[100];

    printf("Enter your password: ");
    scanf("%99s", password); // Prevent buffer overflow

    checkPasswordStrength(password);

    return 0;
}
