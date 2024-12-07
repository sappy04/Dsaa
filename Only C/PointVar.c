#include <stdio.h>

int main()
{
    int var;  // Declare an integer variable
    int *ptr; // Declare a pointer to an integer

    var = 10;   // Assign a value to the variable
    ptr = &var; // Assign the address of the variable to the pointer

    // Display the value of the variable
    printf("Value of var: %d\n", var);

    // Display the address of the variable
    printf("Address of var: %p\n", (void *)&var);

    // Display the value of the variable using the pointer
    printf("Value of var using pointer: %d\n", *ptr);

    // Display the address stored in the pointer
    printf("Address stored in pointer: %p\n", (void *)ptr);

    return 0;
}
