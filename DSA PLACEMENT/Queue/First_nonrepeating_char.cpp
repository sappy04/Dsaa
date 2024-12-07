#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        unordered_map<char, int> count; // Map to store frequency of characters
        queue<char> q;                  // Queue to maintain characters for checking the first non-repeating
        string ans = "";                // Result string

        for (int i = 0; i < A.length(); i++)
        {
            char ch = A[i]; // Current character

            // Increase count for the character
            count[ch]++;

            // Add current character to the queue
            q.push(ch);

            // Remove characters from the queue which are repeating
            while (!q.empty())
            {
                if (count[q.front()] > 1)
                {            // If front element's count > 1, pop it
                    q.pop(); // Remove repeating character from the queue
                }
                else
                {
                    ans.push_back(q.front()); // Non-repeating character, add to result
                    break;                    // Break after finding the first non-repeating character
                }
            }

            // If queue is empty, add '#' to result as no non-repeating character exists
            if (q.empty())
            {
                ans.push_back('#');
            }
        }

        return ans; // Return the result string after processing all characters
    }
};

int main()
{
    Solution sol;
    string A = "aabc";
    cout << sol.FirstNonRepeating(A) << endl; // Output should be "aabc#"
    return 0;
}
