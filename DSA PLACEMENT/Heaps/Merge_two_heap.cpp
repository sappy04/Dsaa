#include <bits/stdc++.h>
using namespace std;

class siuu
{
public:
    void heapify(vector<int> &array, int n, int i) // i index k neeche se pura heapify kar deta hai ye function leaf node ko chor k
    {
        int largest = i;           // jiske neeche se mujhe heapify karna hai us index ko largest maan le aur neeche wale check karle
        int leftchild = 2 * i + 1; // us index ka left child aur right child ko nikal le
        int rightchild = 2 * i + 2;

        if (leftchild < n && array[leftchild] > array[largest]) // dekh le range mai hai ki nahi aur kya mera left child bara hai current element se
        {
            largest = leftchild; // agar left child badha hai current element se to left child ko largest mark kar do
        }
        if (rightchild < n && array[rightchild] > array[largest])
        {
            largest = rightchild;
        }
        if (largest != i) // abhi ka agar largest(from left/right child if any found) pehle k largest k sath match kar gaya then to koi fayda hi nahi hai aur agar nahi match nahi karta then swap karo current largest ko prev largest se and all set
        {
            swap(array[largest], array[i]); // swap kar diya current largest ko new largest k sath
            heapify(array, n, largest);     // reccursively call kar diya
        }
    }

    vector<int> mergeheaps(vector<int> &a, vector<int> &b, int n, int m)
    { // 0 based indexing hai
        // step 1:merge both arrays into 1
        vector<int> ans;
        // ans.push_back(-1);//1 based indexing k liye pehla value hamesha garbage daalna padhega
        for (int i = 0; i < a.size(); i++)
        {
            ans.push_back(a[i]);
        }
        for (int i = 0; i < b.size(); i++)
        {
            ans.push_back(b[i]);
        }
        // step2:heapify the array elements
        int sized = ans.size();
        for (int i = (sized / 2) - 1; i >= 0; i--) // sare leaf nodes ko chor k check kar raha heap hai ki nahi
        {
            heapify(ans, sized, i); // ans ko heapify kar diya
        }
        return ans;
    }
};

int main()
{
    siuu obj;

    int n, m;
    cout << "Enter the size of the first heap: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter elements of the first heap: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Enter the size of the second heap: ";
    cin >> m;
    vector<int> b(m);
    cout << "Enter elements of the second heap: ";
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    vector<int> mergedHeap = obj.mergeheaps(a, b, n, m);

    cout << "The merged max heap is: ";
    for (auto i : mergedHeap)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

// Enter the size of the first heap: 4
// Enter elements of the first heap: 10 5 6 2
// Enter the size of the second heap: 3
// Enter elements of the second heap: 12 7 9
// The merged max heap is: 12 10 9 2 5 7 6 