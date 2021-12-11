#include <iostream>
using namespace std;
#include <vector>

int search(vector<int> &nums, int target)
{
    if (nums.size() == 0)
        return -1;
    if (nums.size() == 1)
        return nums[0] == target ? 0 : -1;
    int left = 0;
    int right = nums.size() - 1;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[0] < nums[mid])
        {
            if (nums[0] < target && target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        else
        {
            if (nums[nums.size()-1] > target && target > nums[mid])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return -1;
}
int main()
{

    system("pause");
    return 0;
}
