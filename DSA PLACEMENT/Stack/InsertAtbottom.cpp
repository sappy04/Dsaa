#include<bits/stdc++.h>
using namespace std;

void checkkaro(stack<int>& s, int element)
{
    if(s.empty()) // agar stack khali hai
    {
        s.push(element); // insert kar diya bottom mai
    }
    else {
        int top = s.top(); // top wala ko pakad liya
        s.pop(); // stack se ek ek karke elements neeche jaa raha hoon
        checkkaro(s, element); // recursive call
        s.push(top); // stack se ek ek karke elements upar daal raha hoon
    }
}

void printStack(stack<int> s) {
    // Stack ko print karna, jahan recursion ke baad elements ko restore kiya jaata hai
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main()
{
    int size;
    cin >> size; // size input liya
    stack<int> s; // stack initialise kar diya
    int inputs;
    for (int i = 0; i < size; i++) {
        cin >> inputs; // numbers input le liya hai
        s.push(inputs); // stack ko bhar diya
    }

    int element;
    cin >> element; // element to be inserted input le liya

    checkkaro(s, element); // bottom pe element dalne ka function call

    cout << "Stack after inserting element at bottom: ";
    printStack(s); // Stack ko print karte hain
    return 0;
}
