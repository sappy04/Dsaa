#include<stdio.h>

int main(void)
{
    int a = 10;
    // declare a pointer
    int *ptr;//=&a;
    // assign value to pointer
    ptr = &a;

    printf("Value at ptr is: %d \n", *ptr);

    printf("Address pointed by ptr is: %p \n", ptr);

    return 0;
}