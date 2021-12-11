#include <iostream>
using namespace std;
#include <vector>
#include<algorithm>

void nextPermutation(vector<int> &nums)
{
    if (nums.size() == 0 || nums.size() == 1)
        return;
    int i = nums.size() - 1;
    while (i > 0 && nums[i] <= nums[i - 1])
    {
        i--;
    }
    if(i>0)
    {
        int j = nums.size() - 1;
        while(j>i-1&&nums[j]<=nums[i-1])
        {
            j--;
        }
        swap(nums[i-1], nums[j]);
    }
    // sort(nums.begin() + i, nums.end());
    int k = nums.size() - 1;
    while(i<k)
    {
        swap(nums[i], nums[k]);
        i++;
        k--;
    }
}
int main()
{

    system("pause");
    return 0;
}
