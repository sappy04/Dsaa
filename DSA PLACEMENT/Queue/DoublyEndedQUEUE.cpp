#include <bits/stdc++.h>
using namespace std;

class Deque
{
    int *arr;
    int qfront;
    int rear;
    int size;

public:
    Deque(int n)
    {
        size = n;
        arr = new int[size]; // Allocate memory for the array
        qfront = rear = -1;
    }

    bool pushfront(int x)
    {
        // Check if the queue is full
        if ((qfront == 0 && rear == size - 1) || (rear == (qfront - 1 + size) % size))
        {
            cout << "Queue is full" << endl;
            return false;
        }
        else if (qfront == -1) // First element insertion
        {
            qfront = rear = 0;
        }
        else if (qfront == 0) // Wrap around in a cyclic manner
        {
            qfront = size - 1;
        }
        else
        {
            qfront--;
        }
        arr[qfront] = x;
        return true;
    }

    bool pushrear(int val)
    {
        // Check if the queue is full
        if ((qfront == 0 && rear == size - 1) || (rear == (qfront - 1 + size) % size))
        {
            cout << "Queue is full" << endl;
            return false;
        }
        else if (qfront == -1) // First element insertion
        {
            qfront = rear = 0;
        }
        else if (rear == size - 1 && qfront != 0) // Wrap around rear
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = val;
        return true;
    }

    int popfront()
    {
        // Check if the queue is empty
        if (qfront == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int ans = arr[qfront];
        arr[qfront] = -1;

        // Reset qfront and rear if only one element was present
        if (qfront == rear)
        {
            qfront = rear = -1;
        }
        else if (qfront == size - 1) // Wrap around front
        {
            qfront = 0;
        }
        else
        {
            qfront++;
        }
        return ans;
    }

    int poprear()
    {
        // Check if the queue is empty
        if (qfront == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int ans = arr[rear];
        arr[rear] = -1;

        if (qfront == rear) // Only one element present
        {
            qfront = rear = -1;
        }
        else if (rear == 0) // Wrap around rear
        {
            rear = size - 1;
        }
        else
        {
            rear--;
        }
        return ans;
    }
};
int main()
{
    // Create a deque of size 5
    Deque dq(5);

    // Test pushing to the front and rear
    cout << "Push to rear: 10 -> " << dq.pushrear(10) << endl;
    cout << "Push to rear: 20 -> " << dq.pushrear(20) << endl;
    cout << "Push to front: 30 -> " << dq.pushfront(30) << endl;
    cout << "Push to front: 40 -> " << dq.pushfront(40) << endl;
    cout << "Push to rear: 50 -> " << dq.pushrear(50) << endl;

    // Trying to push to a full deque
    cout << "Push to rear when full: 60 -> " << dq.pushrear(60) << endl;

    // Test popping from the front and rear
    cout << "Pop from front: " << dq.popfront() << endl;
    cout << "Pop from rear: " << dq.poprear() << endl;
    cout << "Pop from front: " << dq.popfront() << endl;
    cout << "Pop from front: " << dq.popfront() << endl;

    // Push again to check circular nature
    cout << "Push to rear: 70 -> " << dq.pushrear(70) << endl;
    cout << "Push to front: 80 -> " << dq.pushfront(80) << endl;

    // Pop remaining elements
    cout << "Pop from front: " << dq.popfront() << endl;
    cout << "Pop from front: " << dq.popfront() << endl;
    cout << "Pop from front: " << dq.popfront() << endl;

    // Try popping from an empty deque
    cout << "Pop from front when empty: " << dq.popfront() << endl;

    return 0;
}