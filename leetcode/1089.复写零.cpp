/*
 * @lc app=leetcode.cn id=1089 lang=cpp
 *
 * [1089] 复写零
 */
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        int left = 0, n = arr.size();
        int right =  - 1, top = 0;
        while(top<n)
        {
            right++;
            if(arr[right]!=0)
                top++;
            else
                top += 2;
        }
        left = right;
        right = n - 1;
        if (top == n+1)
        {
            arr[right--] = 0;
            left--;
        }
        for (; left >= 0; left--)
        {
            arr[right--] = arr[left];
            if (arr[left] == 0 && right >= 0)
                arr[right--] = 0;
        }
    }
};
/*


// */
// int main()
// {
//     vector<int> arr = {8,4,5,0,0,0,0,7};
//     Solution s;
//     s.duplicateZeros(arr);
//     for (int i = 0; i < arr.size(); i++)
//         cout << arr[i] << " ";

//     return 0;
// }
// @lc code=end
