#include <bits/stdc++.h>
using namespace std;

class TWOStack {
    int *array; // Dynamic array for both stacks
    int top1;   // Top pointer for the first stack
    int top2;   // Top pointer for the second stack
    int size;   // Size of the array

public:
    // Constructor
    TWOStack(int size) {
        this->size = size;
        array = new int[size]; // Allocate memory for the array
        top1 = -1;             // Initialize top1 to -1
        top2 = size;           // Initialize top2 to size (end of array)
    }


    // Push in stack1
    void push1(int data) {
        if (top2 - top1 > 1) { // Check for available space
            top1++;
            array[top1] = data; // Add data to stack1
        } else {
            cout << "Stack Overflow in Stack 1" << endl;
        }
    }

    // Push in stack2
    void push2(int data) {
        if (top2 - top1 > 1) { // Check for available space
            top2--;
            array[top2] = data; // Add data to stack2
        } else {
            cout << "Stack Overflow in Stack 2" << endl;
        }
    }

    // Pop from stack1
    int pop1() {
        if (top1 >= 0) { // Check if stack1 is not empty
            int ans = array[top1];
            top1--;
            return ans; // Return popped value
        } else {
            cout << "Stack Underflow in Stack 1" << endl;
            return -1; // Indicate underflow
        }
    }

    // Pop from stack2
    int pop2() {
        if (top2 < size) { // agar pointer within array hai
            top2++;//array mai to aage hi badh raha hai na
            return ans; // Return popped value
        } else {
            cout << "Stack Underflow in Stack 2" << endl;
            return -1; // Indicate underflow
        }
    }
};

int main() {
    // Create a TWOStack of size 5
    TWOStack stacks(5);

    // Test pushing and popping in stack1
    stacks.push1(1);
    stacks.push1(2);
    stacks.push1(3);

    cout << "Popped from Stack 1: " << stacks.pop1() << endl; // Should print 3

    // Test pushing and popping in stack2
    stacks.push2(10);
    stacks.push2(20);
    stacks.push2(30);

    cout << "Popped from Stack 2: " << stacks.pop2() << endl; // Should print 30

    return 0;
}
