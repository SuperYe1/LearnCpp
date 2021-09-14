#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
447. 回旋镖的数量
给定平面上 n 对 互不相同 的点 points ，其中 points[i] = [xi, yi] 。
回旋镖 是由点 (i, j, k) 表示的元组 ，其中 i 和 j 之间的距离和 i 和 k 之间的距离相等
（需要考虑元组的顺序）。
返回平面上所有回旋镖的数量。
*/

int numberOfBoomerangs(vector<vector<int>> &points)
{
    int res = 0;
    if (points.size() == 1)
        return res;

    for (auto &p : points)
    {
        unordered_map<int, int> cnt;
        for (auto &q : points)
        {
            int dis = (p[0] - q[0]) * (p[0] - q[0]) +
                      (p[1] - q[1]) * (p[1] - q[1]);
            cnt[dis]++;
        }
        for(auto &[_,m]:cnt)
        {
            res += m * (m - 1);
        }
    }
    return res;
}

int main()
{

    return 0;
}