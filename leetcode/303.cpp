#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
310. 最小高度树
树是一个无向图，其中任何两个顶点只通过一条路径连接。 
换句话说，一个任何没有简单环路的连通图都是一棵树。

给你一棵包含 n 个节点的树，标记为 0 到 n - 1 。
给定数字 n 和一个有 n - 1 条无向边的 edges 列表（每一个边都是一对标签），
其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间存在一条无向边。

可选择树中任何一个节点作为根。当选择节点 x 作为根节点时，设结果树的高度为 h。
在所有可能的树中，具有最小高度的树（即，min(h)）被称为 最小高度树 。

请你找到所有的 最小高度树 并按 任意顺序 返回它们的根节点标签列表。
树的 高度 是指根节点和叶子节点之间最长向下路径上边的数量。
*/

vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
{
    if (n == 1)
        return {0};
    vector<vector<int>> relateNum(n);
    vector<int> degree(n);
    vector<int> ans;
    for (auto &edge : edges)
    {
        relateNum[edge[0]].push_back(edge[1]);
        relateNum[edge[1]].push_back(edge[0]);
        degree[edge[0]]++;
        degree[edge[1]]++;
    }

    queue<int> dq;
    for (int i = 0; i < n; i++)
    {
        if (degree[i] == 1)
            dq.push(i);
    }
    int redNum = n;
    while (redNum > 2)
    {
        int nSize = dq.size();
        redNum -= nSize;
        for (int i = 0; i < nSize; i++)
        {
            int tem = dq.front();
            degree[tem]--;
            dq.pop();
            for (auto &v : relateNum[tem])
            {
                if(--degree[v] == 1)
                    dq.push(v);
            }
        }
    }
    while(!dq.empty())
    {
        ans.push_back(dq.front());
        dq.pop();
    }
    return ans;
}

int main()
{
    vector<vector<int>> edges = {{1, 0}, {1, 2}, {1, 3}};
    vector<int> res= findMinHeightTrees(4, edges);
    for(auto& v :res)
        cout << v << endl;
    return 0;
}