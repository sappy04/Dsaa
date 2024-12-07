#include <iostream>
using namespace std;
int selec(int ar[], int n)
{
    int min;
    for (int i = 0; i < (n - 1); i++)
    {
        min = i;
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
    cout << "Enter the size of the array" << endl;
    cin >> n;

    int ma[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ma[i];
    }
    selec(ma, n);
    for (int i = 0; i < n; i++)
    {
        cout << ma[i] << " ";
    }
    return 0;
}