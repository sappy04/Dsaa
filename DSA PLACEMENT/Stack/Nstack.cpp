#include <bits/stdc++.h>
using namespace std;

class Nstack // s ka matlab hai size of array, n ka matlab hai no of stacks q ka matlab hai number of queries  
{
    int *arr; // three different arrays
    int *top;
    int *next;
    int n, s;
    int freespot;

public:
    Nstack(int n, int s) // initialisiting data structure
    {
        this->n = n;
        this->s = s;
        arr = new int[s];  // size of array k equal
        top = new int[n];  // number of stacks k equal
        next = new int[s]; // size of array k equal

        // top ko initialise kara
        for (int i = 0; i < n; i++) // saare top ko -1 se initialise kara
        {
            top[i] = -1;
        }
        // next ko initialise karo
        for (int i = 0; i < s; i++) // next ko initialise kara
        {
            next[i] = i + 1;
        }
        // next k last mai to -1 dalna hai na?
        next[s - 1] = -1;

        // free spot ko initialise karo
        freespot = 0;
    }

    bool push(int x, int m) // pushes x into the mth stack, return true if gets pushed
    {
        // pehle to overflow ko check karo
        if (freespot == -1)
        {
            return false;
        }
        int index = freespot; // dalega to kisi index pe hi na so free spot dekhke daal
        arr[index] = x;       // x ko daaala humne array mai by freespot
        // update free spot
        freespot = next[index]; // free spot update hogaya

        // update next
        next[index] = top[m - 1]; // next ko purane top se initialise kar diya

        // update top
        top[m - 1] = index;
        return true;
    }

    int pop(int m)
    {
        // check underflow condition
        if (top[m - 1] == -1)
        {
            return -1;
        }
        // just push ka ulta karo, down to top approach ka istemal karo
        int index = top[m - 1];
        top[m - 1] = next[index];
        // push karne ka to darkar hi nahi hai
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }
};

int main()
{
    // Stack configuration: 3 stacks within an array of size 6
    int numberOfStacks = 3, arraySize = 6;
    Nstack ns(numberOfStacks, arraySize);

    // Testing the push function
    ns.push(10, 1); // pushes 10 into stack 1
    ns.push(20, 2); // pushes 20 into stack 2
    ns.push(30, 3); // pushes 30 into stack 3
    ns.push(40, 1); // pushes 40 into stack 1

    // Testing the pop function
    cout << "Popped from stack 1: " << ns.pop(1) << endl; // should return 40
    cout << "Popped from stack 2: " << ns.pop(2) << endl; // should return 20
    cout << "Popped from stack 3: " << ns.pop(3) << endl; // should return 30
    cout << "Popped from stack 1: " << ns.pop(1) << endl; // should return 10

    // Testing underflow condition
    cout << "Popped from empty stack 1: " << ns.pop(1) << endl; // should return -1

    // Testing overflow condition
    ns.push(50, 1); // pushes 50 into stack 1
    ns.push(60, 2); // pushes 60 into stack 2
    bool isPushed = ns.push(70, 3); // tries to push into full array
    cout << "Pushing into full array returns: " << isPushed << endl; // should return false

    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;
// class Nstack//s ka matlab hai size of array,n ka matlab hai no of stacks q ka matlab hai number of queries  
// {
//     int *arr; // three different arrays
//     int *top;
//     int *next;
//     int n, s;
//     int freespot;

// public:
//     Nstack(int n, int s) // initialisiting data structure
//     {
//         n = n;
//         s = s;
//         arr = new int[s];  // size of array k equal
//         top = new int[n];  // number of stacks k equal
//         next = new int[s]; // size of array k equal

//         // top ko initialise kara
//         for (int i = 0; i < n; i++) // saare top ko -1 se initialise kara
//         {
//             top[i] = -1;
//         }
//         // next ko initialise karo
//         for (int i = 0; i < s; i++) // next ko initialise kara
//         {
//             next[i] = i + 1;
//         }
//         // next k last mai to -1 dalna hai na?
//         next[s - 1] = -1;

//         // free spot ko initialise karo
//         freespot = 0;
//     }

//     bool push(int x, int m) // pushes x into the mth stack,return true if gets pushed
//     {
//         // pehle to overlflow ko check karo
//         if (freespot == -1)
//         {
//             return false;
//         }
//         int index = freespot; // dalega to kisi index pe hi na so free spot dekhke daal
//         arr[index] = x;         // x ko daaala humne array mai by freespot
//         // update free spot
//         freespot = next[index]; // free spot update hogaya

//         // update next
//         next[index] = top[m - 1];//next ko purane top se initialise kar diya

//         // update top
//         top[m - 1] = index;
//         return true;
//     }
//     int pop(int m)
//     {
//         // check underflow condition
//         if (top[m - 1] == -1)
//         {
//             return -1;
//         }
//         // just push ka ulta karo,down to top approach ka istemal karo
//         int index = top[m - 1];
//         top[m - 1] = next[index];
//         //push karne ka to darkar hi nahi hai
//         next[index] = freespot;
//         freespot = index;
//         return arr[index];
//     }
// };
// int main()
// {

//     return 0;
// }
