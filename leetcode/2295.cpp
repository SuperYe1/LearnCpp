#include "oftenUse.hpp"
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> arrayChange(vector<int> &nums, vector<vector<int>> &operations)
{
    unordered_map<int, int> mp;
    for(int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]] = i;
    }

    int m = operations.size();
    for(int i = 0; i < m; i++)
    {
        int last = operations[i][0];
        int next = operations[i][1];
        nums[mp[last]] = next;
        mp[next] = mp[last];
    }
    return nums;
}
int main()
{
    
    system("pause");
    return 0;
}