#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    int i;
    for (i = n - 1; i > 0; --i)
    {
        if (nums[i] > nums[i - 1])
        {
            swap(nums[i], nums[i - 1]);
            for (int j = 0; j < (n - i) / 2; j++)
                swap(nums[i + 1 + j], nums[n - 1 - j]);
            break;
        }
    }
    if (i == 0)
    {
        for (int i = 0; i < nums.size() / 2; i++)
            swap(nums[i], nums[n - 1 - i]);
    }
}

int main()
{

    system("pause");
    return 0;
}
