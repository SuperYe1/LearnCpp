#include "oftenUse.hpp"
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
{
    int m = grid.size();
    int n = grid[0].size();
    if (m == 1 && n == 1)
        return grid;
    k = k % (m * n);
    vector<vector<int>> ret = grid;
    if (k)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int index = (i * n + j + k) % (m * n);
                int newi = index / n;
                int newj = index % n;
                ret[newi][newj] = grid[i][j];
            }
        }
    }
    return ret;
}

int main()
{
    vector<vector<int>> a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> b = shiftGrid(a, 2);
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[0].size(); j++)
            cout << b[i][j] << " ";
        cout << endl;
    }
    system("pause");
    return 0;
}