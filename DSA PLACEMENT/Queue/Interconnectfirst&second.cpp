#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void interleaveQueue(queue<int> &q)
{
    if (q.empty() || q.size() % 2 != 0)
    {
        cout << "Queue must have even number of elements." << endl;
        return;
    }

    int halfSize = q.size() / 2;
    stack<int> s;

    
    for (int i = 0; i < halfSize; i++)//pehla half bhar diya
    {
        s.push(q.front());
        q.pop();
    }

    
    while (!s.empty())//queue k peeche jor diya
    {
        q.push(s.top());
        s.pop();
    }

    
    for (int i = 0; i < halfSize; i++)//pehla half to peeche bheja wapis
    {
        q.push(q.front());
        q.pop();
    }

   
    for (int i = 0; i < halfSize; i++)//phir se stack mai daala first half ko
    {
        s.push(q.front());
        q.pop();
    }

   
    while (!s.empty())//abhi adha stack mai hai(pehla wala) aur adha queue mai hai(jo stack mai kabhi gaya hi nahi)
    {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}

int main()
{
    queue<int> q;
    int n, value;

    cout << "Enter the number of elements in the queue (even number): ";
    cin >> n;

    if (n % 2 != 0)
    {
        cout << "Number of elements must be even." << endl;
        return 0;
    }

    cout << "Enter the elements of the queue:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        q.push(value);
    }

    interleaveQueue(q);

    cout << "Interleaved queue:" << endl;
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
