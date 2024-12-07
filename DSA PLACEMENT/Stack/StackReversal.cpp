#include <bits/stdc++.h>
using namespace std;

// Function to insert element at the bottom of the stack
void insertAtbottom(stack<int>& s, int element) {
    if (s.empty()) { // agar stack khali hai
        s.push(element); // insert kar diya bottom mai
    }
    else {
        int top = s.top(); // top wala ko pakad liya
        s.pop(); // stack se ek ek karke elements neeche jaa raha hoon
        insertAtbottom(s, element); // recursive call
        s.push(top); // stack se ek ek karke elements upar daal raha hoon
    }
}

// Function to reverse the stack
void reversed(stack<int>& s) {
    if (s.empty()) { // khali hua to reverse karne ka koi scene nahi hai
        return; // khattam
    }
    
    int top = s.top(); // uparwala ko store kar liya
    s.pop(); // pointer kamaya
    reversed(s); // recursive call
    insertAtbottom(s, top); // uparwala ko bottom pe dal diya
}

// Function to print the stack
void printStack(stack<int> s) {
    cout << "Reversed stack is(top to bottom view): ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    int size;
    cin >> size; // size input liya
    stack<int> s; // stack initialise kar diya
    int inputs;
    for (int i = 0; i < size; i++) {
        cin >> inputs; // numbers input le liya hai
        s.push(inputs); // stack ko bhar diya
    }
    
    reversed(s); // stack ko reverse kiya
    printStack(s); // reversed stack ko print kiya
    return 0;
}
