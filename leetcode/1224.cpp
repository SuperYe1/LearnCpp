#include "oftenUse.hpp"
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int maxEqualFreq(vector<int> &nums)
{
    unordered_map<int, int> mp;
    unordered_map<int, int> mp1;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
        mp1[mp[nums[i]]]++;
        mp1[mp[nums[i]] - 1]--;
        if (mp1[mp[nums[i]] - 1] <= 0)
            mp1.erase(mp[nums[i]] - 1);
        if (mp1.size() == 2)
        {
            vector<vector<int>> temp;
            for (auto it : mp1)
            {
                temp.push_back({it.first, it.second});
                if (it.first == 1 && it.second == 1)
                {
                    ans = i;
                }
            }
            if (abs(temp[0][0] - temp[1][0]) == 1)
            {
                if ((temp[0][0] > temp[1][0] && temp[0][1] == 1) ||
                    (temp[0][0] < temp[1][0] && temp[1][1] == 1))
                    ans = i;
            }
        }
        else if(mp1.size() == 1)
        {
            if(mp1.begin()->first == 1 || mp1.begin()->second == 1)
                ans = i;
        }
    }
    return ans + 1;
}

int main()
{
    vector<int> nums = {1,2};
    cout << maxEqualFreq(nums) << endl;
    system("pause");
    return 0;
}