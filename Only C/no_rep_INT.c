#include <stdio.h>

int main() {
    int n;

    // Input number of members
    printf("Enter the number of members: ");
    scanf("%d", &n);

    int members[n];
    int i, j, unique;

    // Input members
    printf("Enter the members:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &members[i]);
    }

    // Print members in sequence without repetition
    printf("The sequence of members without repetition is:\n");

    for (i = 0; i < n; i++) {
        unique = 1;

        // Check for repetition
        for (j = 0; j < i; j++) {
            if (members[i] == members[j]) {
                unique = 0;
                break;
            }
        }

        if (unique) {
            printf("%d ", members[i]);
        }
    }

    printf("\n");

    return 0;
}
