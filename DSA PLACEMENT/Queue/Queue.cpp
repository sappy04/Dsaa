#include <bits/stdc++.h>
using namespace std;

class Queue {
    int *arr;
    int qfront;
    int rear;
    int size;

public:
    Queue() {
        size = 100;
        arr = new int[size];  // Allocate memory for the array
        qfront = 0;
        rear = 0;
    }
    
    void enque(int data) {
        if (rear == size) {
            cout << "Queue is full" << endl;  
        } else {
            arr[rear] = data;
            rear++;
        }
    }

    int deque() {
        if (qfront == rear) {
            return -1;  // Queue is empty
        } else {
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            // Reset queue if it's empty after dequeue
            if (qfront == rear) {
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front() {
        if (qfront == rear) {
            return -1;  // Queue is empty
        } else {
            return arr[qfront];  // Return front element
        }
    }

    bool isempty() {
        return qfront == rear;
    }

    ~Queue() {
        delete[] arr;  // Free allocated memory
    }
};

int main() {
    Queue q;  // Corrected instance of Queue class
    return 0;
}
