#include <iostream>
using namespace std;
void swapp(int ar[], int n)
{
    int temp = 0;
    for (int i = 0; i < n-1; i = i + 2)//i+2 ka karan ye hai ki 0 1 index to change hogaya wapis kyu change kaarna so start from 2 always and n-1 kiya gaya hai to stop out of bound of array
    {

        // temp = ar[i];
        // ar[i] = ar[i + 1];
        // ar[i + 1] = temp;
        swap(ar[i],ar[i+1]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }
}
int main()
{
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    swapp(ar, n);
    return 0;
}