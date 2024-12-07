#include <bits/stdc++.h>
using namespace std;
// Function to find the next smaller element for each element in the array
void nextSmallerElement(int arr[], int n, int next[])
{
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        // Store the current element in a variable
        int currentElement = arr[i];

        // Pop elements from stack that are greater than or equal to current element
        while (!s.empty() && arr[s.top()] >= currentElement)
        {
            s.pop();
        }

        // If stack is not empty, the top of the stack is the next smaller element
        if (!s.empty())
        {
            next[i] = s.top();
        }
        else
        {
            next[i] = n; // No smaller element to the right, so assign n (out of bounds)
        }
        // Push the current element's index onto the stack
        s.push(i);
    }
}

// Function to find the previous smaller element for each element in the array
void prevSmallerElement(int arr[], int n, int prev[])
{
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        // Store the current element in a variable
        int currentElement = arr[i];

        // Pop elements from stack that are greater than or equal to current element
        while (!s.empty() && arr[s.top()] >= currentElement)
        {
            s.pop();
        }

        // If stack is not empty, the top of the stack is the previous smaller element
        if (!s.empty())
        {
            prev[i] = s.top();
        }
        else
        {
            prev[i] = -1; // No smaller element to the left, so assign -1
        }
        // Push the current element's index onto the stack
        s.push(i);
    }
}

int largestRectangleArea(int arr[], int n)
{
    int next[n]; // To store the next smaller element indices
    int prev[n]; // To store the previous smaller element indices

    nextSmallerElement(arr, n, next);
    prevSmallerElement(arr, n, prev);

    int maxArea = INT_MIN; // Initialize maximum area with a very small number

    for (int i = 0; i < n; i++)
    {
        int height = arr[i];
        int width = next[i] - prev[i] - 1;
        int area = height * width;
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

// Function to calculate the maximum area of a rectangle in a binary matrix
int MAXarea(int M[][100], int rows, int cols)
{
    int area = largestRectangleArea(M[0], cols); // Get area of the first row,cols jo hai pehli row ka size hai
    // remaining rows check

    for (int i = 1; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (M[i][j] != 0) // agar koi row ka cell zero nahi hai to is row ko neeche waale row k saath add kar de
            {
                M[i][j] += M[i - 1][j]; // ye row to added row ka result hai
            }
            else
            {
                M[i][j] = 0; // agar koi row ka cell zero hai to usse zero hi rehne de
            }
        }
        area = max(area, largestRectangleArea(M[i], cols));//per row ka size hai ye
    }
    return area;
}

int main()
{
    int N, M;
    cin >> N >> M;

    int M_array[100][100] = {0}; // Assuming max matrix size is 100x100

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> M_array[i][j];
        }
    }

    // Find and print the largest rectangle area in the binary matrix
    cout << "Largest Rectangle Area in Binary Matrix: " << MAXarea(M_array, N, M) << endl;

    return 0;
}