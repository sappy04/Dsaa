#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;

    int sum = 0;
    int prod = 1;
    
    while (n > 0)
    {
        int dig = n % 10;  // Get the last digit
        prod = prod * dig; // Multiply the digit to product
        sum = sum + dig;   // Add the digit to sum
        n = n / 10;        // Remove the last digit
    }

    cout << "Sum is: " << sum << " and Product is: " << prod << endl;
    int dif=prod-sum;
    cout<<"final answer is: "<<dif<<endl;
    return 0;
}
