#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

void myF(vector<int> &candidates, int target, vector<vector<int>> &res, vector<int> &combine, int idx, int sum, vector<bool> &used)
{

    if (sum == target)
    {
        res.push_back(combine);
        return;
    }
    for (int i = idx; i < candidates.size() && candidates[i] + sum <= target; ++i)
    {
        if (i > 0 && candidates[i - 1] == candidates[i] && used[i - 1] == false)
            continue;
        sum += candidates[i];
        combine.push_back(candidates[i]);
        used[i] = true;
        myF(candidates, target, res, combine, i + 1, sum, used);
        used[i] = false;
        sum -= candidates[i];
        combine.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<vector<int>> res;
    vector<bool> used(candidates.size(), false);
    sort(candidates.begin(), candidates.end());
    vector<int> combine;
    myF(candidates, target, res, combine, 0, 0, used);
    return res;
}

int main()
{
    vector<int> candidates = {2, 5, 1, 2, 2};
    int target = 5;
    vector<vector<int>> res = combinationSum2(candidates, target);

    system("pause");
    return 0;
}
