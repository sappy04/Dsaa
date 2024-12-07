#include <bits/stdc++.h>
using namespace std; // mini se chota value hone se formula wise push hoga and pop mai top agar mini nahi hai to formula wise bahar niklega
class Getmini
{
    stack<int> s; // Internal stack to store elements
    int mini;     // Variable to track the minimum element

public:
    // Push function to add an element to the stack
    void push(int data)
    {
        if (s.empty())
        {
            s.push(data);
            mini = data; // Initialize mini with the first data value
        }
        else
        {
            if (data > mini) // stack er bhetorer element er theke jodi asche element boro hoy then normal push else formula push
            {
                s.push(data); // Push the data normally if it's not less than mini
            }
            else
            {
                s.push(2 * data - mini); // formula push mini
                mini = data;             // Update mini to the new data
            }
        }
    }

    // Pop function to remove the top element from the stack
    int pop()
    {
        if (s.empty())
        {
            return -1; // Return -1 if the stack is empty
        }
        int cur = s.top();
        s.pop();

        if (cur >= mini) // agar stack k top value se found out mini bara hai to siddha bahar nikalo else formula wise bahar nikalo
        {
            return cur;
        }
        else
        {
            //original mini store karke nikala
            int prevmin = mini;
            mini = 2 * mini - cur; //stack mai naya mini banaya acc to avaibility
            return prevmin;        // Return the actual minimum value
        }
    }

    // Top function to get the current top of the stack
    int top()
    {
        if (s.empty())
        {
            return -1; // Return -1 if the stack is empty
        }
        int curr = s.top();
        // If the stored value is modified (less than mini), return mini as top
        if (curr < mini)
        {
            return mini; // mini badha hone se mini niklgea
        }
        else
        {
            return curr; // curr badha hone se current niklega
        }
    }

    // Function to check if the stack is empty
    bool isEmpty()
    {
        return s.empty();
    }

    // Function to get the current minimum element in the stack
    int getmin()
    {
        if (s.empty())
        {
            return -1; // Return -1 if the stack is empty
        }
        return mini;
    }
};

int main()
{
    Getmini s;
    s.push(3);
    s.push(5);
    cout << "Minimum: " << s.getmin() << endl; // Should print 3
    s.push(2);
    s.push(1);
    cout << "Minimum: " << s.getmin() << endl; // Should print 1
    s.pop();
    cout << "Minimum: " << s.getmin() << endl; // Should print 2
    s.pop();
    cout << "Top: " << s.top() << endl;        // Should print 5
    cout << "Minimum: " << s.getmin() << endl; // Should print 3

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// class Getmini
// {
//     stack<int> s;
//     int mini;

// public:
//     void push(int data)
//     {
//         // first element
//         if (s.empty())
//         {
//             s.push(data);
//             mini = data; // pehle data ko hi mini declare kar diya
//         }
//         else
//         {
//             // data jo dalega mini se kam hai
//             if (data < mini)
//             {
//                 s.push(2 * data - mini); // formula wise push karna hai
//                 mini = data;             // change mini
//             }
//             else
//             {
//                 s.push(data); // normal push
//             }
//         }
//     }

//     int pop()
//     {
//         if (s.empty())
//         {
//             return -1;
//         }
//         int cur = s.top();
//         s.pop();
//         if (cur > mini) // current agar mini se badha hua to normal pop..mini pehle se hi set hai air current stack ka top hai
//         {
//             return cur; // normal pop
//         }
//         else
//         {
//             int prevmin = mini;
//             int val = 2 * mini - cur;
//             mini = val;
//             return prevmin;
//         }
//     }
//     int top()//dekhoooo
//     {
//         if (s.empty())
//         {
//             return -1;
//         }
//         int curr = s.top();
//         if (curr < mini)
//         {
//             return mini;
//         }
//         else
//         {
//             return curr;
//         }
//     }
//     bool isEmpty()
//     {
//         return s.empty();
//     }
//     int getmin()
//     {
//         if (s.empty())
//         {
//             return -1;
//         }
//         return mini;
//     }
// };
// int main()
// {

//     return 0;
// }