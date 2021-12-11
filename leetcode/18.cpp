#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> result;
    int n = nums.size();
    if (n < 4)
        return result;
    sort(nums.begin(), nums.end());

    for (int first = 0; first < n - 3; first++)
    {
        if (first > 0 && nums[first] == nums[first - 1])
            continue;
        if (nums[first] + nums[first + 1] + nums[first + 2] + nums[first + 3] > target)
            break;
        if (nums[first] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target)
            continue;
        for (int second = first + 1; second < n - 2; second++)
        {
            if (second > first + 1 && nums[second] == nums[second - 1])
                continue;
            if (nums[first] + nums[second] + nums[second + 1] + nums[second + 2] > target)
                break;
            if (nums[first] + nums[second] + nums[n - 2] + nums[n - 1] < target)
                continue;
            int left = second + 1;
            int right = n - 1;
            while (left < right)
            {
                int sum = nums[first] + nums[second] + nums[left] + nums[right];
                if (sum == target)
                {
                    result.push_back({nums[first], nums[second], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    right--;
                }
                else if (sum < target)
                    left++;
                else
                    right--;
            }
        }
    }
    return result;
}
int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    system("pause");
    return 0;
}
