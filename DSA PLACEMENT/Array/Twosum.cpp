#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> twoSum(vector<int> &arr, int target, int n)
{
    vector<pair<int, int>> result;

    vector<pair<int, int>> sortedArr; // ek vector hai jismai mai apne saare eleemnts ko sorted way mai store karna chahata hoon with indices
    for (int i = 0; i < n; i++)
    {
        sortedArr.push_back({arr[i], i}); // array ka har element with index daal raha mai vector mai
    }
    sort(sortedArr.begin(), sortedArr.end()); // Svector ko sort kar diya values k basis pe 

    
    int left = 0, right = n - 1; // 2 pointer set kar diya start(left) and end(right) mai
    while (left < right)//tab tak karo jab tak ye dono overlap nahi kar jaate
    {
        int sum = sortedArr[left].first + sortedArr[right].first;//left ka first matlab sabse pehla element ka value(and not index) & right(last element) ka first matlab ki end k element ka value 

        if (sum == target)//mil gaya too dono pointer ko update karo
        {
            result.push_back({sortedArr[left].first, sortedArr[right].first});
            left++;
            right--;
        }
        else if (sum < target)//sum agar target se chota hai to samne se hi na badhayenge 
        {
            left++; // Increase sum by moving left pointer
        }
        else//sum target se badha hai to badha value ghatane se mil jayega easily to kama right se
        {
            right--; // Decrease sum by moving right pointer
        }
    }

    
    if (result.empty())
    {
        result.push_back({-1, -1});//koi result nahi milla to bhai -1 hi daalo
    }

    return result;
}

int main()
{
    vector<int> arr1 = {2, 7, 11, 13};
    vector<int> arr2 = {1, -1, -1, 2, 2};
    int target1 = 9, target2 = 1;

    // Test Case 1
    vector<pair<int, int>> res1 = twoSum(arr1, target1, arr1.size());
    for (auto p : res1)
    {
        cout << p.first << " " << p.second << endl;
    }

    // Test Case 2
    vector<pair<int, int>> res2 = twoSum(arr2, target2, arr2.size());
    for (auto p : res2)
    {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
// 2 pointer approach hai