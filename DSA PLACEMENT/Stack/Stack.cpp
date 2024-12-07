#include <bits/stdc++.h>
using namespace std;

class Stack
{
    // properties
    int *array; // isspe hi to kaam karunga(variable size ka hai na islliye pointer use kiya hai)
    int top;    // isse hi saare checking honge array mai
    int size;   // array ka size batayega

public:
    // Constructor
    Stack(int size)
    {
        this->size = size;     // size ko initialise kar diya
        array = new int[size]; // array ko bhi initialise kar diya(heap used dynamic memory)
        top = -1;              // top ko bhi initialise kar diya(jab pehla value dalega ++ karke dalenge)
    }

    // member methods
    void push(int data)
    {
        if (top < size - 1)
        {
            top++;             // pointer badhao
            array[top] = data; // aur data daal do
        }
        else
        {
            cout << "stack overflow" << endl;
        }
    }

    void pop()
    {
        if (top >= 0)
        {
            top--; // bas pointer update karde bhai
        }
        else
        {
            cout << "stack underflow" << endl;
        }
    }

    int peek() // check kar rhe hai ki nahi
    {
        if (top >= 0) // top>=0 matlab ek value to atleast hai stack mai
        {
            return array[top]; // top element return kardo
        }
        else
        {
            cout << "stack is empty" << endl;
            return -1; // false wa
        }
    }

    bool isempty()
    {
        if (top == -1) // top to khali hi hai bhai...top to badha hi nahi
        {
            return true; // khaali
        }
        else
        {
            return false; // else bharti
        }
    }
};

int main()
{
    // stack creation
    Stack str(5); // stack create of name str with size 5

    str.push(22);
    str.push(34);
    str.push(99);
    str.push(100);

    cout << str.peek() << " is the top element" << endl; // top element hai 100

    str.pop();                                           // 100 hat gaya
    cout << str.peek() << " is the top element" << endl; // top element hai 99
    str.pop();                                           // 99 hat gaya

    if (str.isempty() == true)
    {
        cout << "stack is empty" << endl;
    }
    else
    {
        cout << "stack is not empty" << endl;
    }

    str.pop();                                           // 34 hat gaya
    cout << str.peek() << " is the top element" << endl; // top element hai 22
    str.pop();                                           // 22 hat gaya ..empty hai khali hai stack

    if (str.isempty() == true)
    {
        cout << "stack is empty" << endl;
    }
    else
    {
        cout << "stack is not empty" << endl;
    }
    str.peek();

    return 0;
}

// #include <bits/stdc++.h>//using stl
// using namespace std;
// int main()
// {
//     stack<int> s;
//     // push operation
//     s.push(2);
//     s.push(3);

//     // pop operation
//     s.pop();

//     //printing the top element
//     cout << "Top element in the stack is " << s.top() << endl;

//     //checking if empty
//     if(s.empty())
//     {
//         cout<<"stack is empty"<<endl;
//     }
//     else
//     {
//         cout<<"stack is not empty"<<endl;
//     }

//     //size
//     cout<<"size of stack is: "<<s.size()<<endl;

//     return 0;
// }