#include "oftenUse.hpp"
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <vector>
using namespace std;

#define N 20010
int p[N] = {0};
int sz[N] = {0};
int ans = 1;

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

void uni(int x, int y)
{
    int rootx = find(x);
    int rooty = find(y);
    if (rootx == rooty)
        return;
    sz[rootx] += sz[rooty];
    p[rooty] = p[rootx];
    ans = max(ans, sz[rootx]);
}

int largestComponentSize(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n;i++)
    {
        int cur = nums[i];
        for (int j = 2; j * j <= cur;j++)
        {
            if(cur%j==0)
                mp[j].push_back(i);
            while(cur%j==0)
                cur /= j;
        }
        if(cur>1)
            mp[cur].push_back(i);
    }
    for (int i = 0;i<= n; i++)
    {
        p[i] = i;
        sz[i] = 1;
    }
    for(auto it:mp)
    {
        vector<int> temp= it.second;
        for (int i = 1; i < temp.size(); i++)
            uni(temp[0],temp[i]);
    }
    return ans;
}
int main()
{
    system("pause");
    return 0;
}