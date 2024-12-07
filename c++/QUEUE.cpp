#include <iostream>
using namespace std;
class stack
{
private:
    int rear,front;
    int ar[6];

public:
    stack()
    {
        rear = -1;
        front =-1;
        for (int i = 0; i < 6; i++)
        {
            ar[i]=0;
        }
    }
    bool isf()
    {
        if (rear >= 5)
            return true;
        else
            return false;
    }
    bool ie()
    {
        if (front==-1&& rear == -1)
            return true;
        else
            return false;
    }
    int enqueue(int v)
    {
        if (isf())
        {
            cout << "queue is full" << endl;
        }
        else if(ie())
        {
            rear=0;
            front=0;
            ar[rear]=v;
        }
        else
        {
            rear++;   
            ar[rear] = v;
        }
    }
    int dequeue()
    {
        int x = 0;
        if (ie())
        {
            cout << "queue is empty" << endl;
        }
        else if(rear==front)
        {
            x = ar[rear];
            ar[rear] = 0;
            rear--;
            front--;
            return x;
        }
        else
        {
            x=ar[front];
            ar[front]=0;
            front++;
            return x;
        }
    }
    void display()
    {
        for (int i = 0; i <6; i++)
        {
            cout<<ar[i]<<" ";
        }
    }
};
int main()
{
    stack s1;
    int chc, v;

    do
    {
        cout << "\nenter the chc: \n0.for exit\n1.for full check\n2.for empty check\n3.push\n4.delete\n5.display" << endl;
        cin >> chc;
        switch (chc)
        {
        case 0:
        {
            break;
        }
        case 1:
        {
            if (s1.isf() == true)
                cout << "full" << endl;
            else
                cout << "not full" << endl;
        }
        break;
        case 2:
        {
            if (s1.ie() == true)
                cout << "empty" << endl;
            else
                cout << "not empty" << endl;
        }
        break;
        case 3:
        {
            cout << "enter elemnt to be inserted" << endl;
            cin >> v;
            s1.enqueue(v);
        }
        break;
        case 4:
        {
            s1.dequeue();
        }
        break;
        case 5:
        {
            s1.display();
        }
        break;
        default:
        {
            cout << "invalid choice" << endl;
        }
        }

    } while (chc != 0);
    return 0;
}