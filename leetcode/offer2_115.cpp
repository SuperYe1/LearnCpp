#include "oftenUse.hpp"
#include <iostream>
#include <queue>
#include <vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

bool sequenceReconstruction(vector<int> &nums, vector<vector<int>> &sequences)
{
    int n = nums.size();
    vector<int> indegrees(n + 1);
    vector<vector<int>> graph(n + 1);
    for(auto sequence:sequences)
    {
        for (int i = 1;i<sequence.size();i++)
        {
            int prev = sequence[i-1];
            int next = sequence[i];
            //if(!graph[prev].find(next))
            if(find(graph[prev].begin(), graph[prev].end(), next)==graph[prev].end())
            {
                graph[prev].emplace_back(next);
                indegrees[next]++;
            }
        }
    }
    queue<int> qu;
    for (int i = 1; i <= n;i++)
    {
        if(!indegrees[i])
            qu.push(i);
    }
    while(!qu.empty())
    {
        if(qu.size()>1)
            return false;
        int num = qu.front();
        qu.pop();
        for(int next:graph[num])
        {
            indegrees[next]--;
            if(indegrees[next]==0)
            {
                qu.push(next);
            }
        }
    }
    return true;
}


int main()
{

    system("pause");
    return 0;
}