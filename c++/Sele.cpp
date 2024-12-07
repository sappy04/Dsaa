#include <iostream>
using namespace std;
int selecsort(int ar[], int n)
{

    for (int i = 0; i < (n - 1); i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (ar[j] < ar[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = ar[min];
            ar[min] = ar[i];
            ar[i] = temp;
        }
    }
}
int main()
{
    int n;
    cout << "Enter the number of elements" << endl;
    cin >> n;
    int myarr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> myarr[i];
    }
    selecsort(myarr, n);
    cout << "after sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << myarr[i] << " ";
    }
    return 0;
}