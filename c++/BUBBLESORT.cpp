#include <iostream>
using namespace std;
void bs(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int flag = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                flag = true;
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
        if (flag == false)
            break;
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
    cout << "before soorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << myarr[i] << " ";
    }
    bs(myarr, n);
    cout << "\nafter soorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << myarr[i] << " ";
    }
    return 0;
}