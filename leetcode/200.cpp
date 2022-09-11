#include "oftenUse.hpp"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int numIslands(vector<vector<char>> &grid)
{
    int dir[][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int m = grid.size(), n = grid[0].size();
    int ans = 0;
    vector<vector<int>> map(m + 2, vector<int>(n + 2, 0));
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
            map[i][j] = grid[i - 1][j - 1] - '0';
    }
    queue<vector<int>> qu;
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (map[i][j] == 0)
                continue;
            qu.push({i, j});
            map[i][j] = 0;
            while (!qu.empty())
            {
                vector<int> temp = qu.front();
                qu.pop();
                for (auto it : dir)
                {
                    int tempx = temp[0] + it[0];
                    int tempy = temp[1] + it[1];
                    if (map[tempx][tempy])
                    {
                        map[tempx][tempy] = 0;
                        qu.push({tempx, tempy});
                    }
                }
            }
            ans++;
        }
    }
    return ans;
}
int main()
{
    vector<vector<char>> grid = {{'1', '1', '0', '0', '0'},
                                 {'1', '1', '0', '0', '0'},
                                 {'0', '0', '1', '0', '0'},
                                 {'0', '0', '0', '1', '1'}};
    cout << numIslands(grid) << endl;

    system("pause");
    return 0;
}