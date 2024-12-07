#include <bits/stdc++.h>
using namespace std;
void findinter(int array1[], int n1, int array2[], int n2)
{
    sort(array1, array1 + n1);
    sort(array2, array2 + n2);
    bool inter = false;
    int i = 0;
    int j=0;
    while (i < n1 && j < n2)
    {
        if (array1[i] < array2[j]) // agar pehla line ka element dusre line se chota hua to age badhao pehle line ka pointer
        {
            i++;
        }
        else if (array1[i] > array2[j]) // agar dusre line ka element pehle line se chota hua to age badhao dusre line ka pointer
        {
            j++;
        }
        else if (array1[i] == array2[j])
        {
            cout << array1[i] << " ";
            i++;
            j++;
            inter = true;
        }
    }
    if (inter == true)
    {
        cout << "Intersection found" << endl;
    }
    else
    {
        cout << "No intersection found" << endl;
    }
}
int main()
{
    int n1;
    cin >> n1;
    int n2;
    cin >> n2;
    int array1[n1];
    int array2[n2];
    for (int i = 0; i < n1; i++)
    {
        cin >> array1[i];
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> array2[i];
    }
    findinter(array1, n1, array2, n2);
    return 0;
}

// 5
// 1 2 3 4 5
// 5
// 9 7 3 4 1