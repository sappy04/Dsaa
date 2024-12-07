#include <stdio.h>

int main() {
    float tax = 0, income;

    // Input income from user
    printf("Enter your income: ");
    scanf("%f", &income);

    // Calculate tax based on income slabs
    if (income <= 150000) {
        tax = 0;
    } else if (income <= 300000) {
        tax = (income - 150000) * 0.10;
    } else if (income <= 500000) {
        tax = (150000 * 0.10) + (income - 300000) * 0.20;
    } else {
        tax = (150000 * 0.10) + (200000 * 0.20) + (income - 500000) * 0.30;
    }

    // Output the calculated tax
    printf("Your tax is: %f\n", tax);

    return 0;
}
