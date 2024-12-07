#include <iostream>
using namespace std;
part(int a[], int s, int e)
{
    int pi = s;
    int piviot = a[e];
    for (int i = s; i < e; i++)
    {
        if (a[i] < piviot)
        {
            int temp = a[i];
            a[i] = a[pi];
            a[pi] = temp;
            pi++;
        }
    }
    int temp = a[e];
    a[e] = a[pi];
    a[pi] = temp;

    return pi;
}
quickky(int a[], int s, int e)
{
    if (s < e)
    {
        int p = part(a, s, e);
        quickky(a, (p + 1), e);
        quickky(a, s, (p - 1));//left part
    }
}
int main()
{
    int n;
    cout << "ENTER THE SIZE" << endl;
    cin >> n;
    int ma[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ma[i];
    }
    quickky(ma, 0, (n - 1));//syntax only first arra,then start index then end index=(size-1)
    cout << "After sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << ma[i] <<" ";
    }
    return 0;
}