#include <iostream>
#include <bitset>
using namespace std;

int main() {
    string binary;
    cin >> binary;

    // Convert binary string to decimal using bitset
    bitset<32> b(binary); // Assuming a maximum of 32 bits
    cout << b.to_ulong() << endl; // Convert to unsigned long and print

    return 0;
}
