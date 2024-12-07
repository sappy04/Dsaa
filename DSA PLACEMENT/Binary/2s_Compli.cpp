#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // Convert the integer to a 32-bit bitset
    bitset<32> b(n);

    // Output the original binary representation
    cout << "THE BINARY IS: " << b << endl;

    // Step 1: Invert the bits to get the 1's complement
    for (int i = 0; i < b.size(); i++) 
    {
        b[i] = !b[i];  // Invert the bit (0 to 1, 1 to 0)
    }

    // Output the 1's complement
    cout << "1's complement: " << b << endl;

    // Step 2: Add 1 to the inverted bits (1's complement) to get the 2's complement
    bool carry = 1;
    for (int i = 0; i < b.size(); i++) 
    {
        if (b[i] == 1 && carry) 
        {
            b[i] = 0;  // 1 + 1 = 0 with a carry
        } 
        else if (b[i] == 0 && carry) 
        {
            b[i] = 1;  // 0 + 1 = 1, no more carry needed
            carry = false;  // Stop the carry as we added 1
        }
        else 
        {
            // No change required if there's no carry
            break;
        }
    }

    // Output the final 2's complement
    cout << "2's complement: " << b << endl;

    return 0;
}




// #include <bits/stdc++.h>
// using namespace std;
// string binaryy(int n)
// {
//     string store;
//     if (n == 0)
//     {
//         store = '1';
//         return store;
//     }
//     while (n > 0)
//     {
//         int rem = n % 2;
//         store += to_string(rem);
//         n = n / 2;
//     }
//     reverse(store.begin(), store.end());
//     return store;
// }
// void twoscompli(int n)
// {
//     if (n >= 0)
//     {
//         string b_ans = binaryy(n);
//         cout << "binary is: " << b_ans << endl;
//         for (int i = 0; i < b_ans.length(); i++) // ones complement
//         {
//             if (b_ans[i] == '0')
//             {
//                 b_ans[i] = '1';
//             }
//             else
//             {
//                 b_ans[i] = '0';
//             }
//         }
//         cout << "ones compliment is: "; // printed 1's complimenet
//         for (int i = 0; i < b_ans.length(); i++)
//         {
//             cout << b_ans[i];
//         }
//         cout << endl;
//     }
//     else
//     {
//     string b_ans = binaryy(abs(n));
//     cout << "binary is: " << b_ans << endl;
//     for (int i = 0; i < b_ans.length(); i++) // ones complement
//     {
//         if (b_ans[i] == '0')
//         {
//             b_ans[i] = '1';
//         }
//         else
//         {
//             b_ans[i] = '0';
//         }
//     }
//     // cout << "ones compliment is: "; // printed 1's complimenet
//     // for (int i = 0; i < b_ans.length(); i++)
//     // {
//     //     cout << b_ans[i];
//     // }
//     // cout << endl;

//     // start of 2s compliment
//     int carry = 1;
//     for (int i = b_ans.length() - 1; i >= 0; i--) // done//important stap...peche add krte hai na 1 wohi hai ye
//     {
//         if (b_ans[i] == '1' && carry == 1)
//         {
//             b_ans[i] = '0';
//         }
//         else if (b_ans[i] == '0' && carry == 1)
//         {
//             b_ans[i] = '1';
//             carry = 0;
//         }
//         else
//         {
//             break;
//         }
//     }
//     if (carry == 1)
//     {
//         b_ans = '1' + b_ans;
//     }

//     cout << "2's complementary is(binary value for negative): " << b_ans << endl;
//     }
// }
// int main()
// {
//     int n;
//     cin >> n;
//     twoscompli(n);
//     return 0;
// }
// // for negative number