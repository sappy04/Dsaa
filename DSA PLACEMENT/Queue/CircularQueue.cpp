#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int *arr;
    int qfront;
    int rear;
    int size;

public:
    Queue()
    {
        size = 100;
        arr = new int[size]; // Allocate memory for the array
        qfront = rear = -1;
    }

    bool enqueue(int val)
    {
        // Check if the queue is full
        if ((qfront == 0 && rear == size - 1) || (rear == (qfront - 1) % (size - 1))) // last wala jo condition hai wo kehta hai ki rear front k ek peeche hai
        {
            cout << "Queue is full" << endl;
            return false; // Fixed spelling mistake from "fasle" to "false"
        }
        // Check if the queue is empty (first element being added)
        else if (qfront == -1)
        {
            qfront = rear = 0;
        }
        else if (rear == size - 1 && qfront != 0) // rear end pe hai and front kahi beech mai hai to rear ko samne le aoo
        {
            rear = 0;
        }
        // Normal enqueue operation
        else
        {
            rear++;
        }
        arr[rear] = val;
        return true;
    }

    int deque()
    {
        // Check if the queue is empty
        if (qfront == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int ans = arr[qfront];
        arr[qfront] = -1;

        if (qfront == rear) // ek hi element hai
        {
            qfront = rear = -1;
        }
        // Wrap around the front if it reaches the end of the array
        else if (qfront == size - 1) // front agar last mai pohuch gaya hai to kheech k samne lao
        {
            qfront = 0;
        }
        else
        {
            qfront++;
        }
        return ans;
    }

    // Additional utility functions for better usability
    int front()
    {
        if (qfront == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[qfront];
    }

    bool isEmpty()
    {
        return qfront == -1;
    }

    ~Queue()
    {
        delete[] arr; // Free the allocated memory
    }
};

int main()
{
    Queue q;
    // Test the queue by enqueueing and dequeuing elements
    return 0;
}
