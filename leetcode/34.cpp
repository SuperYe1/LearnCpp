#include <iostream>
using namespace std;
#include <vector>

vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> result;
    if (nums.size() == 0)
        return {-1, -1};
    if (nums.size() == 1)
    {
        if (nums[0] == target)
            return {0, 0};
        else
            return {-1, -1};
    }
    int l = 0;
    int r = nums.size() - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] >= target)
            r = mid - 1;
        else
            l = mid + 1;
    }
    if (l >= nums.size() || nums[l] != target)
        l = -1;
    result.push_back(l);

    l = 0;
    r = nums.size() - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] > target)
            r = mid - 1;
        else
            l = mid + 1;
    }
    if (r < 0 || nums[r] != target)
        r = -1;
    result.push_back(r);
    return result;
}

int main()
{

    system("pause");
    return 0;
}
