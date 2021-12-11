#include <iostream>
#include <vector>
using namespace std;

/*
最长递增子序列的个数

给定一个未排序的整数数组，找到最长递增子序列的个数。
*/

int findNumberOfLIS(vector<int> &nums)
{
    int n = nums.size(), maxlLen = 0, ans = 0;
    vector<int> dp(n), cnt(n);

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        cnt[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                if (dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    cnt[i] = cnt[j];
                }
                else if (dp[j] + 1 == dp[i])
                {
                    cnt[i] += cnt[j];
                }
            }
        }
        if (dp[i] > maxlLen)
        {
            maxlLen = dp[i];
            ans = cnt[i];
        }
        else if (dp[i] == maxlLen)
            ans += cnt[i];
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 3, 5, 4, 7};
    cout << "findNumberOfLIS == " << findNumberOfLIS(nums) << endl;
    return 0;
}