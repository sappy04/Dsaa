#include <iostream>
using namespace std;

int main()
{
    int rows = 3;  // Define 3 rows

    // Create a jagged array (array of arrays with varying column sizes)
    int **jaggedArray = new int *[rows];

    // Define different column sizes for each row
    jaggedArray[0] = new int[2];  // 1st row has 2 columns
    jaggedArray[1] = new int[3];  // 2nd row has 3 columns
    jaggedArray[2] = new int[4];  // 3rd row has 4 columns

    // Input elements for each row
    cout << "Enter elements for 1st row (2 elements): ";
    for (int i = 0; i < 2; i++)
        cin >> jaggedArray[0][i];

    cout << "Enter elements for 2nd row (3 elements): ";
    for (int i = 0; i < 3; i++)
        cin >> jaggedArray[1][i];

    cout << "Enter elements for 3rd row (4 elements): ";
    for (int i = 0; i < 4; i++)
        cin >> jaggedArray[2][i];

    // Output the jagged array
    cout << "\nJagged Array:" << endl;

    for (int i = 0; i < 2; i++)
        cout << jaggedArray[0][i] << " ";  // Output 1st row
    cout << endl;

    for (int i = 0; i < 3; i++)
        cout << jaggedArray[1][i] << " ";  // Output 2nd row
    cout << endl;

    for (int i = 0; i < 4; i++)
        cout << jaggedArray[2][i] << " ";  // Output 3rd row
    cout << endl;

    // Free allocated memory
    for (int i = 0; i < rows; i++)
        delete[] jaggedArray[i];
    delete[] jaggedArray;

    return 0;
}

//jagged array:
// 10 20 
// 30 40 50 
// 60 70 80 90