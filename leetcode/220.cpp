#include "oftenUse.hpp"
#include <iostream>
#include <math.h>
#include <vector>
#include <unordered_map>
using namespace std;

int getID(int x, long w)
{
    return x < 0 ? (x + 1ll) / w - 1 : x / w;
}
bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
{
    unordered_map<int, int> mp;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        long x = nums[i];
        int id = getID(x, t + 1ll);
        if (mp.count(id))
        {
            return true;
        }
        if (mp.count(id - 1) && abs(x - mp[id - 1]) <= t)
        {
            return true;
        }
        if (mp.count(id + 1) && abs(x - mp[id + 1]) <= t)
        {
            return true;
        }
        mp[id] = x;
        if (i >= k)
        {
            mp.erase(getID(nums[i - k], t + 1ll));
        }
    }
    return false;
}
int main()
{
    cout << getId(-pow(2, 31), 1ll) << endl;
    system("pause");
    return 0;
}