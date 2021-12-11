#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &res, vector<int> &tmp, vector<int> &nums, int i, int k)
{
    if (tmp.size() == k)
    {
        res.push_back(tmp);
        return;
    }
    if (i >= nums.size())
        return;
    tmp.push_back(nums[i]);
    dfs(res, tmp, nums, i + 1, k);
    tmp.pop_back();
    dfs(res, tmp, nums, i + 1, k);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> tmp;
    res.push_back({});
    if (nums.size() == 0)
        return res;
    for (int i = 1; i <= nums.size(); i++)
        dfs(res, tmp, nums, 0, i);
    return res;
}

int main()
{

    system("pause");
    return 0;
}
