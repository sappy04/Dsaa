#include <stdio.h>

int main() {
    float angle1, angle2, angle3, sum;

    // Input the three angles
    printf("Enter the first angle: ");
    scanf("%f", &angle1);

    printf("Enter the second angle: ");
    scanf("%f", &angle2);

    printf("Enter the third angle: ");
    scanf("%f", &angle3);

    // Calculate the sum of the angles
    sum = angle1 + angle2 + angle3;

    // Check if the sum is 180 degrees
    if (sum == 180) {
        printf("The triangle is valid.\n");
    } else {
        printf("The triangle is not valid.\n");
    }

    return 0;
}
