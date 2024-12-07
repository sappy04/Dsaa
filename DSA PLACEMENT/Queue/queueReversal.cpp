#include<bits/stdc++.h>
using namespace std;

// Function to reverse the elements of the queue
queue<int> reverseQueue(queue<int> q) 
{
    stack<int> s; // created stack
    while (!q.empty()) // jab tak queue khali nahi hai
    {
        int element = q.front(); // pehla element queue ka store kar liya
        q.pop(); // queue se element remove kiya
        s.push(element); // stack me element push kiya
    }
    while (!s.empty()) // jab tak stack khali nahi ho raha
    {
        int element = s.top(); // pehla element stack ka store kar liya
        s.pop(); // stack se element remove kiya
        q.push(element); // queue mai element push kiya
    }
    return q;
}

int main() 
{
    queue<int> q;
    
    // Queue me elements push karenge
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    
    cout << "Original Queue: ";
    queue<int> temp = q; // temporary queue for printing original queue
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
    
    // Function ko call karke queue reverse karenge
    q = reverseQueue(q);

    cout << "Reversed Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
