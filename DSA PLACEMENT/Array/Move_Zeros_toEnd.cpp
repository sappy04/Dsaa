#include <iostream>
using namespace std;
void movezero(int array[], int n)
{
    int nzeroIndex = 0;
    for (int i = 0; i < n; i++)
    {
        if (array[i] != 0)
        {
            array[nzeroIndex] = array[i];//array mai hi saree non zero values daal diya
            nzeroIndex++;
        }
    }
    for (int i = nzeroIndex; i < n; i++)//phir last updated index se array mai saree zero bhar do till size
    {
        array[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
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
    movezero(array, n);
    return 0;
}