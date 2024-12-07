#include <iostream>
using namespace std;
class stack
{
private:
    int top, a[6];

public:
    stack()
    {
        top = -1;
        for (int i = 0; i < 6; i++)
        {
            a[i] = 0;
        }
    }
    bool iF()
    {
        if (top >= 5)
            return true;
        else
            return false;
    }
    bool iE()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
    int push(int v)
    {
        if (iF())
        {
            cout << "full bro!" << endl;
        }
        else
        {
            top++;
            a[top] = v;
        }
    }
    int peek(int pos)
    {
        if (iE())
        {
            cout << "empty bro!" << endl;
        }
        else
        {
            return a[pos];
        }
    }
    int pop()
    {
        if (iE())
        {
            cout << "empty bro!" << endl;
        }
        else
        {
            int x = a[top];
            a[top] = 0;
            top--;
            return x;
        }
    }
    void display()
    {
        cout << "The elements are: " << endl;
        for (int i = 5; i>= 0; i--)
        {
            cout << a[i] << " ";
        }
    }
};
int main()
{
    stack s1;
    int chc, v, pos;
    do
    {    
    cout << "enter 0 for exit" << endl;
    cout << "enter 1 for full check" << endl;
    cout << "enter 2 for empty check" << endl;
    cout << "enter 3 for push" << endl;
    cout << "enter 4 for peek" << endl;
    cout << "enter 5 for pop" << endl;
    cout << "enter 6 for display" << endl;
    cin >> chc;
    switch (chc)
    {
    case 0:
        break;
    case 1:
    {
        if (s1.iF())
            cout << "stack is full" << endl;
        else
            cout << "stack is not full" << endl;
    }
    break;
    case 2:
    {
        if (s1.iE())
            cout << "stack is empty" << endl;
        else
            cout << "stack is not empty" << endl;
    }
    break;
    case 3:
    {
        cout << "enter the element" << endl;
        cin >> v;
        s1.push(v);
    }
    break;
    case 4:
    {
        cin >> pos;
        s1.peek(pos);
    }
    break;
    case 5:
    {
        cout << "The popped element is :" << endl;
        s1.pop();
    }
    break;
    case 6:
    {
        cout << "The elements are :" << endl;
        s1.display();
    }
    break;
    default:
        cout << "Invalid choice" << endl;
    }
    }while(chc!=0);
    return 0;
}

// #include<iostream>

// #include<string>

// using namespace std;

// class Stack {
//   private:
//     int top;
//   int arr[5];

//   public:
//     Stack() {
//       top = -1;
//       for (int i = 0; i < 5; i++) {
//         arr[i] = 0;
//       }
//     }

//   bool isEmpty() {
//     if (top == -1)
//       return true;
//     else
//       return false;
//   }
//   bool isFull() {
//     if (top == 4)
//       return true;
//     else
//       return false;
//   }

//   void push(int val) {
//     if (isFull()) {
//       cout << "stack overflow" << endl;
//     } else {
//       top++; // 1
//       arr[top] = val;
//     }
//   }

//   int pop() {
//     if (isEmpty()) {
//       cout << "stack underflow" << endl;
//       return 0;
//     } else {
//       int popValue = arr[top];
//       arr[top] = 0;
//       top--;
//       return popValue;
//     }
//   }

//   int count() {
//     return (top + 1);
//   }

//   int peek(int pos) {
//     if (isEmpty()) {
//       cout << "stack underflow" << endl;
//       return 0;
//     } else {
//       return arr[pos];
//     }
//   }

//   void change(int pos, int val) {
//     arr[pos] = val;
//     cout << "value changed at location " << pos << endl;
//   }

//   void display() {
//     cout << "All values in the Stack are " << endl;
//     for (int i = 4; i >= 0; i--) {
//       cout << arr[i] << endl;
//     }
//   }
// };

// int main() {
//   Stack s1;
//   int option, postion, value;

//   do {
//     cout << "What operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
//     cout << "1. Push()" << endl;
//     cout << "2. Pop()" << endl;
//     cout << "3. isEmpty()" << endl;
//     cout << "4. isFull()" << endl;
//     cout << "5. peek()" << endl;
//     cout << "6. count()" << endl;
//     cout << "7. change()" << endl;
//     cout << "8. display()" << endl;
//     cout << "9. Clear Screen" << endl << endl;

//     cin >> option;
//     switch (option) {
//     case 0:
//       break;
//     case 1:
//       cout << "Enter an item to push in the stack" << endl;
//       cin >> value;
//       s1.push(value);
//       break;
//     case 2:
//       cout << "Pop Function Called - Poped Value: " << s1.pop() << endl;
//       break;
//     case 3:
//       if (s1.isEmpty())
//         cout << "Stack is Empty" << endl;
//       else
//         cout << "Stack is not Empty" << endl;
//       break;
//     case 4:
//       if (s1.isFull())
//         cout << "Stack is Full" << endl;
//       else
//         cout << "Stack is not Full" << endl;
//       break;
//     case 5:
//       cout << "Enter position of item you want to peek: " << endl;
//       cin >> postion;
//       cout << "Peek Function Called - Value at position " << postion << " is " << s1.peek(postion) << endl;
//       break;
//     case 6:
//       cout << "Count Function Called - Number of Items in the Stack are: " << s1.count() << endl;
//       break;
//     case 7:
//       cout << "Change Function Called - " << endl;
//       cout << "Enter position of item you want to change : ";
//       cin >> postion;
//       cout << endl;
//       cout << "Enter value of item you want to change : ";
//       cin >> value;
//       s1.change(postion, value);
//       break;
//     case 8:
//       cout << "Display Function Called - " << endl;
//       s1.display();
//       break;
//     case 9:
//       system("cls");
//       break;
//     default:
//       cout << "Enter Proper Option number " << endl;
//     }

//   } while (option != 0);

//   return 0;
// }