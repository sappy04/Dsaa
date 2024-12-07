#include <iostream>
#include <bitset>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    bitset<32> binary(n); // converted decimal to binary
    string s = binary.to_string();//converted binary to string
    int index = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {//found the 1st occurence of 1 in the binary
            index = i;
            break;
        }
    }

   
    string stri = s.substr(index);//short sized my string
    cout << "Binary: " << stri << endl;
    int size = stri.size();//noted the size of the shorted string

    
    bitset<32> significant_bits(stri);//converted my shorted string to binary    

    
    for (int i = 0; i < size; i++) {
        significant_bits[i] = !significant_bits[i];//1's complememnt
    }
    
    cout << "1's complement: " << significant_bits.to_string().substr(32 - size) << endl;//shortening of string

  
    unsigned long ones_complement_decimal = significant_bits.to_ulong();//string to decimal
    cout << "Decimal equivalent of 1's complement: " << ones_complement_decimal << endl;

    return 0;
}
