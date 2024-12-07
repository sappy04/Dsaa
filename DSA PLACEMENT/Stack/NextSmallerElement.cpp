#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m;
    cin >> m;
    int array[m];
    for (int i = 0; i < m; i++)
    {
        cin >> array[i];//jo bhi value hai array mai liya hai abhi bas stack se check karenge
    }
    
    stack<int> s; // Stack is initially empty
    s.push(-1);   // khali stack mai -1 daala
    vector<int> ans(m); // Vector to store the answers(sab zero hai andar)
    
    // Start from the last element to optimize
    for (int i = m - 1; i >= 0; i--)
    {
        int current = array[i]; // Store the current element from array

        while (s.top() >= current)//top agar chota hua current element se to hum current element ko stack mai dalenge
        {
            s.pop();//jaise hi s.top mai badha value millega current element se usse pop karenge
        }
        
       
        ans[i] = s.top();//ye answer vector  ai ith position pe comparison ka result store karta hai
        s.push(current);//push kar diya curr element ko kyuki stack mai , current element se bhi chota value ka number top mai hai
        
    }
    
    // Output the result
    cout << ans[0] << endl;//next smaller element k liye from left to right hamesha ans[0]
    
    return 0;
}
