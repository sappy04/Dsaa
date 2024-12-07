#include <bits/stdc++.h>
using namespace std;
// Function to insert an element in sorted order in the stack
void sorted(stack<int> &s, int element)
{
    // Agar stack khali hai ya stack ka top element is se chhota hai toh directly push karenge
    if (s.empty() || s.top() < element)
    {
        s.push(element);
        return; // khattam
    }

    // Agar upar wala element chhota nahi hai
    int top = s.top(); // ek value chota karke wapis se dekhenge by recursion
    s.pop();
    sorted(s, element);

    s.push(top); // sort kakre ghusane k baad wapis se restore kar diya popped value ko
}

// Recursive function to sort the stack
void sortstack(stack<int> &s) // bc stack ko khali karke sort bulayenge
{
    // Agar stack khali hai toh kuch bhi sort karne ka zaroorat nahi
    if (s.empty())
    {
        return;
    }

    int top = s.top(); // empty karne mai lagge padhe hai
    s.pop();
    sortstack(s);

    sorted(s, top); // initially khali hi start karega phir sort ka logic use karega
}

// Function to print the stack from top to bottom
void printStack(stack<int> s)
{
    cout << "top view" << endl;
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main()
{
    int size;
    cin >> size;  // size input le liya
    stack<int> s; // stack initialise kar diya
    int inputs;
    for (int i = 0; i < size; i++)
    {
        cin >> inputs;  // numbers input le liya hai
        s.push(inputs); // stack ko bhar diya
    }

    sortstack(s);  // stack ko sort kiya
    printStack(s); // sorted stack ko print kiya
    return 0;
}

// 5
// -2 -5 9 7 1