#include <bits/stdc++.h>
using namespace std;
bool issafe(int row, int col, vector<vector<int>> &board, int val)
{
    int n = board.size();
    for (int i = 0; i < n; i++)//row aur col ko initialise karne k liye ek hi loop ko use kar lunga
    {
        // row check
        if (board[row][i] == val) // ek row mai check kar raha ki aisa value issi row kahi aur bhi exist karta hai kya?
        {
            return false; // agar haa then false
        }
        // col check
        if (board[i][col] == val)
        {
            return false;
        }
        // matrix mera 3*3[badha matrix mai ,chota matrix mai distributed hai na(3*3 mai)?] hi hai na?
        if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == val)
        {
            return false;
        }
    }
    return true; // agar safe hai to true return karna
}
bool solve(vector<vector<int>> &board)
{
    int n = board.size();             // board ka size note kar liya maine
    for (int row = 0; row < n; row++) // row
    {
        for (int col = 0; col < n; col++) // col check
        {
            if (board[row][col] == 0) // agar khali hai to
            {
                for (int val = 1; val <= 9; val++) // values insert karne k liye khali space mai
                {
                    if (issafe(row, col, board, val))
                    {
                        board[row][col] = val;             // empty space hai aur safe hai to daalo bhai
                        bool bakioperation = solve(board); // baki sab aaise hi recurssion soolve karega
                        if (bakioperation)
                        {
                            return true;
                        }
                        else
                        {
                            // backtrack
                            board[row][col] = 0;
                        }
                    }
                } // agar yaha tak values nahiid al paa rahe hai then land dalega bhai aur kuch value
                return false;
            }
        }
    }
}
void solvesudoku(vector<vector<int>> &soduku)
{
    solve(soduku);
}
int main()
{
    vector<vector<int>> sudoku = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    cout << "Input Sudoku:" << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }

    solvesudoku(sudoku);

    cout << "\nSolved Sudoku:" << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}