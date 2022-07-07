/*
 * @lc app=leetcode.cn id=532 lang=cpp
 *
 * [532] 数组中的 k-diff 数对
 */
#include<iostream>
#include<vector>
using namespace std;


// @lc code=start
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0, n = nums.size();
        int left = 0, right = 0;
        for (left = 0; left < n;left++)
        {
            if(left==0 || nums[left]!=nums[left-1])
            {
                while(right<n && (right<=left ||nums[right]-nums[left]<k))
                    right++;
                if(right<n && nums[right]-nums[left]==k)
                    res++;
            }
        }
        return res;
    }
};
// @lc code=end

