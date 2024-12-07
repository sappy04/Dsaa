#include <iostream>
#include <vector>
#include <algorithm> // For std::copy
using namespace std;

int main() {
    vector<int> source = {1, 2, 3, 4, 5}; // Source vector

    vector<int> destination(source.size()); // Destination vector with the same size

    // Copy elements from source to destination
    copy(source.begin(), source.end(), destination.begin());

    // Print the destination vector using a traditional for loop with index
    cout << "Destination vector: ";
    for (int i = 0; i < destination.size(); ++i) {
        cout << destination[i] << " ";
    }
    cout << endl;

    return 0;
}
