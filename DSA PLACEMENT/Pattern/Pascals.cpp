#include<iostream>
using namespace std;

// Function to calculate factorial
int factorial(int n) {
    if(n == 0 || n == 1) {
        return 1;
    }
    int fact = 1;
    for(int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function to calculate binomial coefficient
int binomialCoefficient(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

// Function to print Pascal's Triangle
void printPascalsTriangle(int rows) {
    for(int i = 0; i < rows; i++) {
        // Print leading spaces for formatting
        for(int j = 0; j < rows - i - 1; j++) {
            cout << "  ";  // Two spaces for each empty slot
        }

        // Print numbers in the row
        for(int j = 0; j <= i; j++) {
            cout << binomialCoefficient(i, j) << "   "; // Three spaces for separation
        }
        cout << endl; // Move to the next line after printing each row
    }
}

int main() {
    int rows;
    cout << "Enter the number of rows for Pascal's Triangle: ";
    cin >> rows;

    printPascalsTriangle(rows);

    return 0;
}
