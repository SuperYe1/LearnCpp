#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/* 暴力求解 , 超时
int minArr(vector<vector<int>> &max, int x, int y)
{
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int minVal = INT_MAX;
    int m = max.size(), n = max[0].size();
    for (auto dir : dirs)
    {
        int i = x + dir[0], j = y + dir[1];
        if (0 <= i && i < m && 0 <= j && j < n)
            minVal = min(minVal, max[i][j]);
    }
    return minVal;
}
vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
{
    int m = isWater.size(), n = isWater[0].size();
    vector<vector<int>> res(isWater);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            res[i][j] ^= 1;
    }
    if (m == 1 && n == 1)
        return res;

    bool isChange = true;
    while (isChange)
    {
        isChange = false;
        for (int i = 0; i < res.size(); i++)
        {
            for (int j = 0; j < res[0].size(); j++)
            {
                if (res[i][j] == 0)
                    continue;
                int temp = minArr(res, i, j) + 1;
                if (res[i][j] != temp)
                {
                    res[i][j] = temp;
                    isChange = true;
                }
            }
        }
    }
    return res;
}
*/

vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
{
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m = isWater.size(), n = isWater[0].size();
    vector<vector<int>> res(m, vector<int>(n, -1));
    queue<pair<int, int>> qs;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isWater[i][j])
            {
                res[i][j] = 0;
                qs.emplace(i,j);
            }
        }
    }
    
    while (!qs.empty())
    {
        auto q = qs.front();
        for(auto dir:dirs)
        {
            int x = q.first + dir[0], y = q.second + dir[1];
            if(0<=x&&x<m&&0<=y&&y<n&&res[x][y]== -1)
            {
                res[x][y] = res[q.first][q.second] + 1;
                qs.emplace(x, y);
            }
        }
        qs.pop();
    }
    return res;
}

int main()
{

    system("pause");
    return 0;
}