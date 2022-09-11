#include "oftenUse.hpp"
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<vector<int>> groupThePeople(vector<int> &groupSizes)
{

    unordered_map<int, vector<int>> groups;
    int n = groupSizes.size();
    for (int i = 0; i < n; i++)
    {
        int size = groupSizes[i];
        groups[size].emplace_back(i);
    }
    vector<vector<int>> groupList;
    for (auto &[size, people] : groups)
    {
        int groupCount = people.size() / size;
        for (int i = 0; i < groupCount; i++)
        {
            vector<int> group;
            int start = i * size;
            for (int j = 0; j < size; j++)
            {
                group.emplace_back(people[start + j]);
            }
            groupList.emplace_back(group);
        }
    }
    return groupList;
}
int main()
{
    vector<vector<int>> ans;
    vector<int> grid = {2, 1, 3, 3, 3, 2};
    ans = groupThePeople(grid);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    system("pause");
    return 0;
}
