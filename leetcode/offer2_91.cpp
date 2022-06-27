#include <iostream>
#include <vector>
using namespace std;

/* 暴力递归求解，超时
int minRes = INT_MAX;

void findCost(vector<vector<int>> &costs, int index, int lastChose, int nowCost)
{
    cout<<"index: "<<index<<"  costs.size(): "<<costs.size()<<endl;
    if (index == costs.size())
    {
        minRes = min(nowCost, minRes);
        return;
    }
    if(nowCost >= minRes)
        return;
    for (int i = 0; i < 3;i++)
    {
        if(i == lastChose)
            continue;
        int nextIndex = index+1;
        findCost(costs, nextIndex, i, nowCost + costs[index][i]);
    }
    return;
}

int minCost(vector<vector<int>> &costs)
{
    for (int i = 0; i < 3;i++)
    {
        findCost(costs, 0, i, 0);
    }
    return minRes;
}
*/

/* 动态规划
int minCost(vector<vector<int>> &costs)
{
    int n = costs.size();
    vector<vector<int>> dp(n+1,vector<int>(3));
    for (int i = 1; i < n + 1;i++)
    {
        for (int j = 0;j<3; j++)
        {
            dp[i][j] = min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + costs[i-1][j];
        }
    }
    return min(dp[n][0], min(dp[n][1], dp[n][2]));
}
*/

/* 动态规划优化 */
int minCost(vector<vector<int>> &costs)
{
    int n = costs.size();
    vector<int> dp(3);
    for (int i = 0; i < 3; i++)
        dp[i] = costs[0][i];
    for (int i = 1; i < n; i++)
    {
        vector<int> temp(dp);
        for (int j = 0; j < 3; j++)
        {
            dp[j] = min(temp[(j + 1) % 3], temp[(j + 2) % 3]) + costs[i][j];
        }
    }
    return min(dp[0], min(dp[1], dp[2]));
}

int main()
{
    vector<vector<int>> costs = {{3, 5, 3}, {6, 17, 6}, {7, 13, 18}, {9, 10, 18}};
    // vector<vector<int>> costs = {{17, 2, 17}};
    cout << minCost(costs) << endl;

    system("pause");
    return 0;
}