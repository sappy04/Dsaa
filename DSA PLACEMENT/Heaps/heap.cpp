#include <bits/stdc++.h>
using namespace std;

class heap
{
public:
    int array[100]; // basic needed components
    int size;

    heap()
    {
        size = 0;      // agar khali hai tree to us liye
        array[0] = -1; // pehla wala array ka element hamesha -1 rahega, fixed hai
    }

    void insert(int val) // val daal rahe hai
    {
        size = size + 1;    // new size banaya jo bhi size hai +1 karke back mai jor diya
        int index = size;   // is updated size ko pakar liya array mai dalne k liye
        array[index] = val; // array k end mai daal diya

        while (index > 1) // jab tak mera index 1 se zyada hai array mai karte karo
        {
            int parent = index / 2;           // parent ka index nikaalne ke liye
            if (array[parent] < array[index]) // agar parent ka bacha bada hai parent se then to bhai swap karo aur agar parent bada hai aur agar parent bada hai parent se then to kuch karna hai nahi
            {
                swap(array[parent], array[index]); // swap kar diya value ko
                index = parent;                    // swap hone k baad original index to agge kahi chala gaya aur parent index k jagah pe agaya to ussi parent ko index mark diya
            }
            else
            {
                return; // sab normal hai
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++) // pehla wala to print karna hai nahi isliye 1 se till size ka end
        {
            cout << array[i] << " ";
        }
    }

    void deleteRoot()
    {
        if (size == 0) // kuch hai hi nahi heap mai
        {
            cout << "Heap is empty!" << endl;
            return;
        }

        // array mai kuch to hai,jo bhi hai last element ko samne lao first poition pe
        array[1] = array[size];

        size--; // last element ko upar le liya to neeche wala ko -- karke inaccessible hi bana diya

        // Step 3: Heapify the root element
        int index = 1;                      // mujhe top most element hatana hai isiliye index hamesha 1 pe set rahega
        while (index <= size)               // jab tak mera index badh badh kar size k equal nahi ho jata
        {                                   // tab tak uska
            int leftchild = 2 * index;      // left child ka index nikalo and
            int rightchild = 2 * index + 1; // right child ka index

            // check kar kya mera left child array k range k andar hai aur apne top element se badha hai agar hai to top ko swap kardo leftchild se
            if (leftchild < size && array[leftchild] > array[index])
            {
                swap(array[index], array[leftchild]); // swapped
                index = leftchild;                    // index ko wapis se top pe set kar diya kyuki mera top element hi abhi left child hai
            }

            // Compare with right child
            else if (rightchild < size && array[rightchild] > array[index])
            {
                swap(array[index], array[rightchild]);
                index = rightchild;
            }
            else
            {
                return; // If no swap is needed, exit the loop
            }
        }
    }
};
void heapify(int array[], int n, int i) // i index k neeche se pura heapify kar deta hai ye function leaf node ko chor k
{
    int largest = i;       // jiske neeche se mujhe heapify karna hai us index ko largest maan le aur neeche wale check karle
    int leftchild = 2 * i; // us index ka left child aur right child ko nikal le
    int rightchild = 2 * i + 1;

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
void heapsort(int array[],int n)
{
    int size=n;//size store kar liya 
    while(size>1)//tab tak karo jab tak pehle index taak nahi pohuch jate
    {
        swap(array[size],array[1]);//last walle ko pehel wale se swap karo
        size--;//array ka size kam kar do kyuki akhri mai giggest element aa chuka hai sorted hai
        heapify(array,size+1,1);//last element ko jo ki abhi pehle position pe hai usko heap mai sahi position mai lao
    }//and all set
}

int main()
{
    heap h;

    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    cout << "Heap elements: ";
    h.print();
    cout << endl;

    h.deleteRoot(); // Delete the root element

    cout << "Heap after deleting root: ";
    h.print();
    cout << endl;

    cout << "heapify kar raha from array input" << endl;
    int array[6] = {-1, 54, 53, 55, 52, 50};
    int n = sizeof(array) / sizeof(array[0]);

    //heapify wala function
    for (int i = (n / 2); i > 0; i--) // sare leaf nodes ko chor k check kar raha heap hai ki nahi
    {
        heapify(array, n, i);
    }
    cout << "array after heapify" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;


    cout << "Sorting the array using heap sort:" << endl;
    heapsort(array, n);
    for (int i = 1; i <= n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;


    return 0;
}
