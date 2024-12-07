#include <bits/stdc++.h>
using namespace std;
class nQueue
{
public: // variables
    int n;
    int k;      // kitne no.of queues
    int *front; // saare arrays hai
    int *rear;  // saare arrays hai
    int *arr;   // saare arrays hai
    int freespot;
    int *next; // saare arrays hai

public:
    nQueue(int n, int k)
    {
        this->n = n;
        this->k = k;
        front = new int[k]; // front bana diya k size ka
        rear = new int[k];
        for (int i = 0; i < k; i++) // k queues ke front aur rear ko initialize kiya
        {
            front[i] = -1;
            rear[i] = -1;
        }

        next = new int[n];
        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1; // saare free spaces aagaye array k
        }
        next[n - 1] = -1;

        arr = new int[n]; // array jismai saare values ghusenge
        freespot = 0;     // hamesha zero hi rahega
    }

    void enqueue(int data, int qn) // data aur konse queue mai karna hai wo queue number
    {
        // overflow check
        if (freespot == -1)
        {
            cout << "Queue is full" << endl;
            return;
        }

        // push karna hai to pehla khali jagah?
        int index = freespot;

        // freespot ko update kiya
        freespot = next[index];

        // check for first element
        if (front[qn - 1] == -1)
        {
            front[qn - 1] = index; // pehla element khali hai to freespot mai value daal do
        }
        else // link karna hota hai
        {
            next[rear[qn - 1]] = index; // ek existing k rear ko uske apne bichde element se jora via rear
        }

        // occupied next ko -1 se mark kiya
        next[index] = -1;

        // rear ko update kar diya
        rear[qn - 1] = index;

        // push element
        arr[index] = data;
    }

    int deque(int qn)
    {
        // underflow
        if (front[qn - 1] == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        // index to pop
        int index = front[qn - 1]; // pehal element se hi hamesha pop hoga isisliye
        // abhi front ko aage badhao
        front[qn - 1] = next[index];

        // freespot ko manage karo
        next[index] = freespot; // peeche koi freespot available ko samne se just popped freespot se link kiya
        freespot = index;       // freespot ko samne leke agaya
        return arr[index];
    }
};

int main()
{
    nQueue nq(10, 3);

    // Perform enqueue operations
    nq.enqueue(10, 1);
    nq.enqueue(20, 1);
    nq.enqueue(30, 2);
    nq.enqueue(40, 2);
    nq.enqueue(50, 3);

    // Perform dequeue operations
    cout << "Dequeued from queue 1: " << nq.deque(1) << endl;
    cout << "Dequeued from queue 2: " << nq.deque(2) << endl;
    cout << "Dequeued from queue 3: " << nq.deque(3) << endl;

    // Perform more operations
    nq.enqueue(60, 1);
    nq.enqueue(70, 3);

    cout << "Dequeued from queue 1: " << nq.deque(1) << endl;
    cout << "Dequeued from queue 3: " << nq.deque(3) << endl;
    return 0;
}



// class nQueue
// {
// public: // variables
//     int n;
//     int k;      // kitne no.of queues
//     int *front; // saare arrays hai
//     int *rear;  // saare arrays hai
//     int *arr;   // saare arrays hai
//     int freespot;
//     int *next; // saare arrays hai
// public:
//     nQueue(int n, int k)
//     {
//         this->n = n;
//         this->k = k;
//         front = new int[k]; // front bana diya k size ka
//         rear = new int[k];
//         for (int i = 0; i < n; i++)
//         {
//             front[i] = -1; // donno arrays ko set kar diya
//             rear[i] = -1;
//         }

//         next = new int[n];
//         for (int i = 0; i < n; i++)
//         {
//             next[i] = i + 1; // saare free spaces aagaye array k
//         }
//         next[n - 1] = -1;

//         arr = new int[n]; // array jismai saare values ghusenge
//         freespot = 0;     // hamesha zero hi rahega
//     }
//     void enqueue(int data, int qn) // data aur konsequeue mai karna hai wo queue number
//     {
//         //overflow check
//         if(freespot==-1)
//         {
//             cout<<"Queue is full"<<endl;
//             return;
//         }
//         //push karna hai to pehla khali jagah?
//         int index=freespot;

//         //freespot ko update kiya
//         freespot=next[index];

//         //check for first element
//         if(front[qn-1]==-1)
//         {
//             front[qn-1]=index;//pehla element khali hai to freespot mai value daal do
//         }
//         else//link karna hota hai
//         {
//            next[rear[qn-1]]=index;//ek existing k rear ko uske apne bichde element se jora via rear 
//         }
        
//         //occupied next ko -1 se mark kiya
//         next[index]=-1;

//     //rear ko upate kar diya
//     rear[qn-1]=index;
 
//     //push element
//     arr[index]=data;

//     }
//     int deque(int qn)
//     {
//         //underflow
//         if(front[qn-1]==-1)
//         {
//             cout<<"Queue is empty"<<endl;
//             return -1;
//         }

//         //index to pop
//         int index=front[qn-1];//pehal eleemnt se hi hamesha pop hoga isisliye
//         //abhi front ko aage badhao
//         front[qn-1]=next[index];

//         //freesot ko manage karo
//         next[index]=freespot;//peeche koi frreespot available ko samne se just popped freespot se link kiya
//         freespot=index;//freespot ko samne leke agaya
//         return arr[index];
//     }
// };