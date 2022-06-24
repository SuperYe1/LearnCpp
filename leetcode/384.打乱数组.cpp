/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
private:
    vector<int> nums,original;

public:
    Solution(vector<int> &nums) : nums(nums), original(nums) {}

    vector<int> reset()
    {
        return original;
    }

    vector<int> shuffle()
    {
        random_shuffle(nums.begin(), nums.end());
        return nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end
