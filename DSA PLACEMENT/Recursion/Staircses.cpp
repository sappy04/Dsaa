#include <iostream>
using namespace std;

int ways(int stairs) {
    if (stairs == 0) {
        return 1; // One way to stay at the ground (do nothing)
    }
    if (stairs < 0) {
        return 0; // No way to reach a negative number of stairs
    }
    
    // Calculate the number of ways recursively
    int ans=ways(stairs - 1) + ways(stairs - 2);
    return ans;
}

int main() {
    int stairs;
    cout<<"enter the number of stairs"<<endl;
    cin >> stairs;
    
    int nwaystoreach = ways(stairs);
    cout << nwaystoreach;
    
    return 0;
}
//3->3

//2->2