// #include <iostream>
// #include <bitset>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;

//     // Create a bitset of size 32 for the integer n
//     bitset<32> binary(n);  

//     // Output the binary representation
//     cout << "Binary representation: " << binary << endl;

//     int count = 0;

//     // Loop to count the number of 1s in the binary representation
//     for (int i = 0; i < 32; i++) {
//         if (binary[i] == 1) {  // Check if the i-th bit is 1
//             count++;
//         }
//     }

//     // Output the count of 1s
//     cout << "Number of 1s in the binary representation: " << count << endl;

//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;  

//     int count = 0;
//     while (n > 0)
//     {
//         int x=n%10;
        
//         if (x==1)
//         {
//             count++;
//         }
//         n/=10;
//     }

//     cout << "Count of 1s: " << count << endl;
//     return 0;
// }

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int maxLength = 0;   // To store the maximum length of consecutive 1s
    int currentLength = 0; // To store the length of the current sequence of 1s

    while (n > 0)
    {
        int x = n % 10;

        if (x == 1)
        {
            // Increment the current sequence length
            currentLength++;
        }
        else
        {
            // Update the maximum length if the current sequence is longer
            if (currentLength > maxLength)
            {
                maxLength = currentLength;
            }
            // Reset the current sequence length
            currentLength = 0;
        }
        
        // Move to the next digit
        n /= 10;
    }

    // Check once more after the loop in case the longest sequence ends at the last digit
    if (currentLength > maxLength)
    {
        maxLength = currentLength;
    }

    cout << "Largest sequence of 1s: " << maxLength << endl;

    return 0;
}