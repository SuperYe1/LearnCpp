#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &res, vector<int> &nums, vector<int> &combine, int size, int cur)
{
    if (size == combine.size())
    {
        res.push_back(combine);
        return;
    }
    for (int i = cur; i < nums.size(); i++)
    {
        if (i > cur && nums[i] == nums[i - 1])
            continue;
        combine.push_back(nums[i]);
        dfs(res, nums, combine,size, i + 1);
        combine.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> combine;
    res.push_back(combine);
    sort(nums.begin(), nums.end());
    for (int i = 1; i <= nums.size(); i++)
        dfs(res, nums, combine, i, 0);
    return res;
}

int main()
{

    system("pause");
    return 0;
}
