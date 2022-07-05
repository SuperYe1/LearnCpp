#include "oftenUse.hpp"
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

/*DFS
void dfs(vector<vector<int>> &isConnected, vector<int>&visit, int i)
{
    for (int j = 0;j<isConnected.size();j++)
    {
        if(isConnected[i][j]==1 && !visit[j])
        {
            visit[j] = 1;
            dfs(isConnected,visit,j);
        }
    }
}
int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();
    vector<int> visit(n);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if(!visit[i])
        {
            dfs(isConnected, visit, i);
            res++;
        }
    }

    return res;
}
*/

int findParent(vector<int> &parent, int index)
{
    if (parent[index] != index)
        parent[index] = findParent(parent, parent[index]);
    return parent[index];
}

void unionIndex(vector<int> &parent, int indexi, int indexj)
{
    parent[findParent(parent, indexi)] = findParent(parent, indexj);
}
int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();
    vector<int> parent(n);
    int res = 0;
    for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (isConnected[i][j])
                unionIndex(parent, i, j);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (parent[i] == i)
            res++;
    }
    return res;
}

int main()
{

    system("pause");
    return 0;
}