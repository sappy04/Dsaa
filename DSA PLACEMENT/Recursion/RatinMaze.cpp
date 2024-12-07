#include <bits/stdc++.h>
using namespace std;

// Function to check if the current cell is safe to move
bool isSafe(int x, int y, int n, int visited[][100], int m[][100])
{
    if (x >= 0 && x < n && y >= 0 && y < n && visited[x][y] == 0 && m[x][y] == 1)
    {
        return true;
    }
    return false;
}

// Recursive function to find paths
void solve(int m[][100], int n, string ans[], int x, int y, int visited[][100], string path, int &ansIndex)
{
    // Base case: If we reach the bottom-right corner
    if (x == n - 1 && y == n - 1) // bottom right corner is destination
    {
        ans[ansIndex++] = path; // path mai ans hai daal ho ans array mai
        return;
    }

    visited[x][y] = 1; // Mark current cell as visited

    // Check all four possible directions: Down, Left, Right, Up
    // Down
    if (isSafe(x + 1, y, n, visited, m))
    {
        solve(m, n, ans, x + 1, y, visited, path + 'D', ansIndex);
    }

    // Left
    if (isSafe(x, y - 1, n, visited, m))
    {
        solve(m, n, ans, x, y - 1, visited, path + 'L', ansIndex);
    }

    // Right
    if (isSafe(x, y + 1, n, visited, m))
    {
        solve(m, n, ans, x, y + 1, visited, path + 'R', ansIndex);
    }

    // Up
    if (isSafe(x - 1, y, n, visited, m))
    {
        solve(m, n, ans, x - 1, y, visited, path + 'U', ansIndex);
    }

    visited[x][y] = 0; // Mark current cell as unvisited when backtracking
}

// Function to find all possible paths in the matrix
int findPath(int m[][100], int n, string ans[])
{
    int ansIndex = 0;
    if (m[0][0] == 0 || m[n - 1][n - 1] == 0) // Check if start or end is blocked
        return 0;

    int visited[100][100] = {0}; // Initialize visited matrix

    string path = "";
    solve(m, n, ans, 0, 0, visited, path, ansIndex);

    return ansIndex; // Return the number of paths found
}

int main()
{
    // Example usage
    int n;
    cout << "Enter the size of the matrix: ";
    cin >> n;

    int matrix[100][100];
    cout << "Enter the matrix elements (0 for blocked, 1 for open):\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    string paths[100]; // Array to store paths
    int size = findPath(matrix, n, paths);

    cout << "All possible paths:\n";
    for (int i = 0; i < size; ++i)
    {
        cout << paths[i] << "\n";
    }

    return 0;
}

// 4
// 1 0 0 0 
// 1 1 0 1 
// 1 1 0 0
// 0 1 1 1
    // All possible paths:
    // DDRDRR
    // DRDDRR