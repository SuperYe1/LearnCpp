#include <iostream>
using namespace std;
#include <algorithm>
#include <cmath>
#include <vector>

int threeSumClosest(vector<int> &nums, int target)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int x = 1e7;
    for (int first = 0; first < n; first++)
    {
        if (first > 1 && nums[first] == nums[first - 1])
        {
            continue;
        }
        int third = n - 1;
        int second = first + 1;
        while (second < third)
        {
            int sum = nums[first] + nums[second] + nums[third];
            if (sum == target)
                return target;
            if (abs(sum - target) < abs(x - target))
            {
                x = sum;
            }
            if (nums[first] + nums[second] + nums[third] > target)
            {
                third--;
            }
            else if (nums[first] + nums[second] + nums[third] < target)
            {
                second++;
            }
        }
    }
    return x;
}
int main()
{
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    int result = threeSumClosest(nums, target);

    // int n = nums.size();
    // sort(nums.begin(), nums.end());
    // int x = 1e7;
    // for (int first = 0; first < n; first++)
    // {
    //     if (first > 1 && nums[first] == nums[first - 1])
    //     {
    //         continue;
    //     }
    //     int third = n - 1;
    //     int second = first + 1;
    //     while (second < third)
    //     {
    //         int sum = nums[first] + nums[second] + nums[third];
    //         if (sum == target)
    //             return target;
    //         if (abs(sum - target) < abs(x - target))
    //         {
    //             x = sum;
    //         }
    //         if (nums[first] + nums[second] + nums[third] > target)
    //         {
    //             third--;
    //         }
    //         else if (nums[first] + nums[second] + nums[third] < target)
    //         {
    //             second++;
    //         }
    //     }
    // }
    cout << result << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i];
    }
    system("pause");
    return 0;
}
