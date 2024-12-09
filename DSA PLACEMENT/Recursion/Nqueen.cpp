#include <bits/stdc++.h>
using namespace std;
void addsol(vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    vector<int> temp; // ek storage create kiya aur usmai saare ans store kar dunga
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp); // ans mai saare values ko daal diya
}
bool issafe(int row, int col, vector<vector<int>> &board, int n)
{
    int x = row;
    int y = col;
    // check for same row
    while (y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        y--;
    }
    // for upper diagonal
    x = row;
    y = col;
    while (x >= 0 && y >= 0) // x aur y mere deebe k bahar nahi jana chahiye(starting)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        y--; // col to ghat hi raha hai
        x--; // row bhi upar jaa raha hai na isliye --
    }
    // for lower diagonal
    x = row;
    y = col;
    while (x < n && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        y--; // col ek peeche jaa raha hai na
        x++; // aur row to ek badh raha hai neeche jaane se isliye
    }

    return true; // yha tak agaa hai to bhai safe hai
}
void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    // base case mere saare col bhar gaye hai
    if (col == n) // agar mera col badhte badhte n ho jata hai(max size)
    {
        addsol(ans, board, n); // board mai mere jitne soln baane padhe hai mai unhe ans mai daal dunga
        return;
    }

    for (int row = 0; row < n; row++) // dekh bhai pehla row mai quuen place karke mai test kar raha ki next col mai position hai kya(ye kaam recursion kar raha hai)?agar nahi to same col mai next row mai try karo
    {
        if (issafe(row, col, board, n)) // agar rakhna safe hai
        {
            board[row][col] = 1;           // rakh diya queen
            solve(col + 1, ans, board, n); // next col mai kaha kaha baitha sakta wo kaam ye kar raha
            // backtrack kar
            board[row][col] = 0; // agar sahi solution nahi hai queen ko hatao
        }
    }
}
vector<vector<int>> nqueens(int n) // kitne queen ko leke kaam karna hai
{
    vector<vector<int>> board(n, vector<int>(n, 0)); // board banaya->n rows ka and n colums ka jiske value saare zero hai(row,col)
    vector<vector<int>> ans;
    solve(0, ans, board, n); // 0th column se start kar raha mai,ans bhej raha ,board bhej raha aur kitne queen hai
    return ans;
}
int main()
{
    int n;
    cout << "Enter the number of queens (N): ";
    cin >> n;

    // Get all solutions for the N-Queens problem
    vector<vector<int>> solutions = nqueens(n);

    // Display the solutions
    cout << "Number of solutions: " << solutions.size() << endl;
    for (int i = 0; i < solutions.size(); i++)
    {
        cout << "Solution " << i + 1 << ":" << endl;
        for (int j = 0; j < n * n; j++)
        {
            if (j % n == 0 && j > 0)
                cout << endl;
            cout << solutions[i][j] << " ";
        }
        cout << endl
             << endl;
    }
    return 0;
}