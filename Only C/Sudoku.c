#include <stdio.h>
#include <stdbool.h>

#define N 9

// Function to print the Sudoku grid
void printGrid(int grid[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Check if placing num in grid[row][col] is valid
bool isSafe(int grid[N][N], int row, int col, int num) {
    // Check if num is not repeated in current row and column
    for (int x = 0; x < N; ++x) {
        if (grid[row][x] == num || grid[x][col] == num)
            return false;
    }
    
    // Check if num is not repeated in current 3x3 sub-grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[i + startRow][j + startCol] == num)
                return false;
        }
    }
    
    return true;
}

// Solve the Sudoku puzzle using backtracking
bool solveSudoku(int grid[N][N]) {
    int row, col;
    bool empty = false;
    
    // Find an empty cell in the grid
    for (row = 0; row < N; ++row) {
        for (col = 0; col < N; ++col) {
            if (grid[row][col] == 0) {
                empty = true;
                break;
            }
        }
        if (empty)
            break;
    }
    
    // If no empty cell is found, the grid is solved
    if (!empty)
        return true;
    
    // Try placing numbers 1 to 9 in the empty cell
    for (int num = 1; num <= 9; ++num) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid))
                return true;
            grid[row][col] = 0; // Backtrack
        }
    }
    
    return false;
}

int main() {
    int grid[N][N];
    
    printf("Enter the Sudoku puzzle (9x9 grid with 0 for empty cells):\n");
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &grid[i][j]);
        }
    }
    
    if (solveSudoku(grid)) {
        printf("Solved Sudoku puzzle:\n");
        printGrid(grid);
    } else {
        printf("No solution exists for the Sudoku puzzle.\n");
    }
    
    return 0;
}
