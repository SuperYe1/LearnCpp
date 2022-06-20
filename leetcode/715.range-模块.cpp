/*
 * @lc app=leetcode.cn id=715 lang=cpp
 *
 * [715] Range 模块
 */

// @lc code=start
#include <iostream>
#include <map>
using namespace std;

class RangeModule
{
private:
    map<int, int> mp;

public:
    RangeModule()
    {
    }

    void addRange(int left, int right)
    {
        auto it = mp.upper_bound(left);
        if (it != mp.begin())
        {
            auto start = prev(it);
            if (start->second >= right)
                return;
            if (start->second >= left)
            {
                left = start->first;
                mp.erase(start);
            }
        }
        while (it != mp.end() && it->first <= right)
        {
            right = max(it->second,right);
            it = mp.erase(it);
        }
        mp[left] = right;
    }

    bool queryRange(int left, int right)
    {
        auto it = mp.upper_bound(left);
        return it != mp.begin() && right <= prev(it)->second;
    }

    void removeRange(int left, int right)
    {
        auto it = mp.upper_bound(left);
        if (it != mp.begin())
        {
            auto start = prev(it);
            if (start->second >= right) {
                int ri = start->second;
                if (start->first == left) {
                    mp.erase(start);
                }
                else {
                    start->second = left;
                }
                if (right != ri) {
                    mp[right] = ri;
                }
                return;
            }
            else if (start->second > left) {
                start->second = left;
            }
        }
        while(it != mp.end() && it->first < right)
        {
            if(it->second <= right)
               it = mp.erase(it);
            else
            {
                mp[right] =  it->second;
                it = mp.erase(it);
                //break;
            }
        }
    }
};

// int main()
// {

//     system("pause");
//     return 0;
// }
/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
// @lc code=end
