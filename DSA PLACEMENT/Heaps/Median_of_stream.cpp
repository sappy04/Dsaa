#include <bits/stdc++.h>
using namespace std;

int signum(int a, int b) // left/right mai kon badha hai uske upar numbers return karta hai
{
    if (a == b) // left aur right donno same length ka hai
    {
        return 0;
    }
    else if (a > b) // left side badha hai
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void callmedian(vector<int> &array, priority_queue<int> &maxheap, priority_queue<int, vector<int>, greater<int>> &minheap, int &median, int element) // ismai bas median calculate hoga
{
    switch (signum(maxheap.size(), minheap.size()))
    {
    case 0: // left aur right ka size same hai
    {
        if (element > median) // right part mai dalega aur median calculate kr lena
        {
            minheap.push(element);
            median = minheap.top();
        }
        else // left part mai ghusa element
        {
            maxheap.push(element);
            median = maxheap.top();
        }
    }
    break;

    case 1: // left side badha hai matlab right mai value dalne se hi balanced ho jayega
    {
        if (element > median)
        {
            minheap.push(element);
            median = (maxheap.top() + minheap.top()) / 2;
        }
        else // left side badha hai par left side mai hi entry hona hai to transfer karna padhga to balance
        {
            minheap.push(maxheap.top()); // transferring
            maxheap.pop();               // transferred
            maxheap.push(element);
            median = (maxheap.top() + minheap.top()) / 2;
        }
    }
    break;

    case -1: // right side badha hai
    {
        if (element > median) // right side badha hai par right side mai hi entry hona hai to transfer karna padhga to balance
        {
            maxheap.push(minheap.top()); // transferring to left
            minheap.pop();               // transferred
            minheap.push(element);
            median = (maxheap.top() + minheap.top()) / 2;
        }
        else // left mai aise hi kam hai ...seedha values daalne se hi normal ho jayega
        {
            maxheap.push(element);
            median = (maxheap.top() + minheap.top()) / 2;
        }
    }
    break;
    }
}

vector<int> findmedian(vector<int> &array, int n) // array aur array ka size, ismai kya kya mera basic needs hai solve karne k liye wo sab hai
{
    vector<int> ans;
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    int median = 0; // median ko 0 initialise kar

    for (int i = 0; i < n; i++)
    {
        callmedian(array, maxheap, minheap, median, array[i]); // ye function mujhe median laake deta hai
        ans.push_back(median);
    }
    return ans; // ans mai mere saare median stored hai
}

int main()
{
    vector<int> array = {5, 15, 1, 3};         // input array->ek element jab hai tabh 5 hi hai jab 2 elements  agya hai tab even ka median apply hua to even size k upar phir jab 3 hua 3 ka size k upar median formula use hua hai
    int n = array.size();                      // size of array
    vector<int> result = findmedian(array, n); // har ek baar input k liye mujhe median nikalana hai

    for (int x : result) // median ko print kar raha hai
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

//5 10 5 4 