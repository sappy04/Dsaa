#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false; // Numbers <= 1 are not prime
    if (num == 2) return true;  // 2 is the only even prime number
    if (num % 2 == 0) return false; // Even numbers greater than 2 are not prime
    // Check for factors from 3 to sqrt(num), only odd numbers need to be checked
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false; // num is divisible by i, so it's not prime
    }
    return true; // num is a prime number
}

// Function to get the next prime number after the given number
int getNextPrime(int current) {
    int num = current + 1;
    while (!isPrime(num)) {
        num++; // Increment num until we find a prime number
    }
    return num; // Return the next prime number
}

// Function to fill the matrix with prime numbers in a spiral order from the center
void fillMatrix(int n, int matrix[n][n]) {
    int prime = 2; // Start with the first prime number
    int row = n / 2; // Start from the middle row
    int col = n / 2; // Start from the middle column
    matrix[row][col] = prime; // Fill the center cell with the first prime number
    prime = getNextPrime(prime);

    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // Right, Down, Left, Up
    int dir = 0; // Start with the right direction
    int steps = 1; // Number of steps to take in the current direction

    while (steps < n) {
        for (int i = 0; i < 2; ++i) { // Two turns for each layer
            for (int j = 0; j < steps; ++j) {
                row += directions[dir][0];
                col += directions[dir][1];
                matrix[row][col] = prime;
                prime = getNextPrime(prime);
            }
            dir = (dir + 1) % 4; // Change direction
        }
        steps++;
    }

    // Fill the last layer
    for (int i = 0; i < steps - 1; ++i) {
        row += directions[dir][0];
        col += directions[dir][1];
        matrix[row][col] = prime;
        prime = getNextPrime(prime);
    }
}

// Function to print the matrix with formatted output
void printMatrix(int n, int matrix[n][n]) {
    int width = 5; // Width of each cell for alignment
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%*d ", width, matrix[i][j]); // Print each number with specified width
        }
        printf("\n"); // Print a new line after each row
    }
}

int main() {
    int n;
    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Matrix size must be positive.\n");
        return 1; // Exit if invalid matrix size
    }

    int matrix[n][n]; // Declare a 2D array for the matrix

    // Initialize the matrix with zeros
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = 0;
        }
    }

    // Fill the matrix with prime numbers in a spiral order starting from the center
    fillMatrix(n, matrix);

    // Print the matrix
    printf("Spiral Matrix filled with prime numbers:\n");
    printMatrix(n, matrix);

    return 0; // Successful completion
}




