#include<bits/stdc++.h>
using namespace std;
queue<int> modify(queue<int> q,int k)
{
    stack<int> s;
    for(int i=0;i<k;i++)//pehle k elements dal gaye stack mai
    {
        int val=q.front();
        q.pop();
        s.push(val);
    }
    //abhi stack se dalenge wapis queue mai
    while(!s.empty())//jab tak khali nahi hai daalo bc
    {
        int val=s.top();
        s.pop();
        q.push(val);
    }
    int t=q.size()-k;//baki elements ko tackle karne k liye unka size le liya
    while(t--)//ek value samne se nikal k peeche jayega phir 1- hoga aise hi hota jayega as soon as one elements goes out
    {
        int top=q.front();
        q.pop();
        q.push(top);//samne se nikal k peeche jor diya
    }
    return q;
}
int main()
{
    queue<int> q;

    // Example queue initialization
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    int k = 3; // Number of elements to reverse

    // Call modify function
    queue<int> modifiedQueue = modify(q, k);

    // Print the modified queue
    while (!modifiedQueue.empty())
    {
        cout << modifiedQueue.front() << " ";
        modifiedQueue.pop();
    }

return 0;
}