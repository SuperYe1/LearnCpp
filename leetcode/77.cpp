#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &res, vector<int> &temp, int cur, int n, int k)
{
    if (temp.size() == k)
    {
        res.push_back(temp);
        return;
    }
    if (temp.size() + n - cur + 1 < k)
        return;
    temp.push_back(cur);
    dfs(res, temp, cur + 1, n, k);
    temp.pop_back();
    dfs(res, temp, cur + 1, n, k);
}

vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> res;
    vector<int> temp;
    dfs(res, temp, 1, n, k);
}

int main()
{

    system("pause");
    return 0;
}
