#include <iostream>
#include <vector>
using namespace std;

bool search(vector<int> &nums, int target)
{
    int n = (int)nums.size();
    if (!n)
    {
        return false;
    }
    if (n == 1)
    {
        return nums[0] == target ? true : false;
    }
    int left = 0, right = n - 1, mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return true;
        if (nums[left] == nums[mid])
        {
            left++;
            continue;
        }
        if (nums[0] <= nums[mid])
        {
            if (nums[0] <= target && nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        else
        {
            if (nums[mid] < target && nums[n - 1] >= target)
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return false;
}
int main()
{

    system("pause");
    return 0;
}
