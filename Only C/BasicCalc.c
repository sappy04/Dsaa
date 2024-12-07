#include <stdio.h>

int main() {
    int choice;
    float num1, num2, result;

    while(1) {
        // Display the menu
        printf("\n*** Menu-based Calculator ***\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulo\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        // If the user selects to exit, break the loop
        if (choice == 6) {
            printf("Exiting the calculator. Goodbye!\n");
            break;
        }

        // Take inputs for the operations, except for Exit
        printf("Enter first number: ");
        scanf("%f", &num1);
        printf("Enter second number: ");
        scanf("%f", &num2);

        // Perform the selected operation
        switch (choice) {
            case 1:
                result = num1 + num2;
                printf("Result of addition: %.2f\n", result);
                break;
            case 2:
                result = num1 - num2;
                printf("Result of subtraction: %.2f\n", result);
                break;
            case 3:
                result = num1 * num2;
                printf("Result of multiplication: %.2f\n", result);
                break;
            case 4:
                if (num2 != 0) {
                    result = num1 / num2;
                    printf("Result of division: %.2f\n", result);
                } else {
                    printf("Error! Division by zero.\n");
                }
                break;
            case 5:
                // Cast the numbers to int for modulo operation
                if ((int)num2 != 0) {
                    result = (int)num1 % (int)num2;
                    printf("Result of modulo: %.0f\n", result);
                } else {
                    printf("Error! Division by zero.\n");
                }
                break;
            default:
                printf("Invalid choice! Please choose a number between 1 and 6.\n");
        }
    }

    return 0;
}
