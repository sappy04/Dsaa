#include <iostream>
using namespace std;
void sorted_rotated(int array[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if ((array[i] > array[i + 1]) % n)// %sign is for rotational array and if only 1 element is greater than the next elemnt then only its in sorted order
        {
            count++;
        }
    }
    if (count <= 1)
    {
        cout<<"sorted and rotated"<<endl;
    }
    else
    {
        cout<<"not sorted and rotated"<<endl;
    }
} 
int main()
{
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    sorted_rotated(array, n);

    return 0;
}