/*
 * @lc app=leetcode.cn id=719 lang=cpp
 *
 * [719] 找出第 K 小的数对距离
 */
#include<iostream>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums.front();
        while(left<right)
        {
            int mid = left + (right - left) / 2;
            int cnt = 0;
            for (int i = 0, j = 0; j < n;j++)
            {
                while(nums[j]-nums[i]>mid)
                    i++;
                cnt += j - i;
            }
            if(cnt>=k)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};

// @lc code=end

