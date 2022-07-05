#include "oftenUse.hpp"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int res = INT_MAX;

bool dfs(int resRoad, int nowRoad, int nowFule, vector<vector<int>> &stations, int index, int times)
{
    bool ans = false;
    if (resRoad <= nowFule)
    {
        res = min(times, res);
        return true;
    }
    if (index >= stations.size() || nowFule < stations[index][0] - nowRoad)
        return ans;
    ans = dfs(resRoad - stations[index][0], nowRoad + stations[index][0],
              nowFule - stations[index][0],
              stations, index + 1, times);
    ans = ans || dfs(resRoad - stations[index][0], nowRoad + stations[index][0],
                     nowFule - stations[index][0] + stations[index][1],
                     stations, index + 1, times + 1);
    return ans;
}

/*
int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
{
    int n = stations.size();
    vector<long> dp(n + 1);
    dp[0] = startFuel;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            if (dp[j] >= stations[i][0])
            {
                dp[j + 1] = max(dp[j + 1], dp[j] + stations[i][1]);
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        if (dp[i] >= target)
            return i;
    }
    return -1;
}
*/

int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
{
    int ans = 0, n = stations.size(), flue = startFuel, nowLoad = 0;
    priority_queue<int> q;
    for(int i = 0; i <= n; i++)
    {
        int curr = i < n ? stations[i][0] : target;
        flue -= curr - nowLoad;
        while(flue<0&&!q.empty())
        {
            flue += q.top();
            q.pop();
            ans++;
        }
        if(flue<0)
            return -1;
        if(i<n)
        {
            q.push(stations[i][1]);
            nowLoad = curr;
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> stations = {{25, 25}, {50, 25}, {75, 25}};
    cout << minRefuelStops(100, 25, stations) << endl;
    system("pause");
    return 0;
}