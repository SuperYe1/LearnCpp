#include <iostream>
using namespace std;
#include <vector>
#include<algorithm>

void backtrack(vector<int> &nums,vector<vector<int>> &res,vector<int> &combine)
{
    if(combine.size()==nums.size())
    {
        res.push_back(combine);
        return;
    }

    for(int i = 0; i < nums.size(); i++)
    {
        if(find(combine.begin(), combine.end(), nums[i]) != combine.end())
        continue;
        combine.push_back(nums[i]);
        backtrack(nums,res,combine);
        combine.pop_back();
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> combine;
    backtrack(nums,res,combine);
    return res;
}

int main()
{

    system("pause");
    return 0;
}
