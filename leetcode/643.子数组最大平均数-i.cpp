/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */
#include<iostream>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0.0;        
        for(int i = 0; i < k;i++)
            sum+=nums[i];
        double maxSum = sum;
        for (int i = k; i < nums.size();i++)
        {
            sum = sum + nums[i] - nums[i - k];
            maxSum = max(maxSum,sum);
        }
        return maxSum/k;
    }
};
// @lc code=end

