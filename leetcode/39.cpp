#include <iostream>
using namespace std;
#include <vector>
#include<algorithm>

void myF(vector<int> &candidates,int target,vector<vector<int>> &res,vector<int> &combine,int idx)
{
    if(idx==candidates.size())
        return;
    if(target==0)
    {
        res.push_back(combine);
        return;
    }
    myF(candidates,target,res,combine,idx+1);
    if(target-candidates[idx]>=0)
    {
        combine.push_back(candidates[idx]);
        myF(candidates,target-candidates[idx],res,combine,idx);
        combine.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> res;
    vector<int> combine;
    sort(candidates.begin(), candidates.end());
    myF(candidates,target,res,combine,0);
    return res;
}

int main()
{
    vector<vector<int>> res;
    vector<int> candidates = {2};
    int target = 8;
    int index = 0;
    if(target%candidates[index] == 0)
    res.push_back(vector<int>(target/candidates[index],candidates[index]));
    for (int i = 0; i < res.size();i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}
