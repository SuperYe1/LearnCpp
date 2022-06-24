/*
 * @lc app=leetcode.cn id=1108 lang=cpp
 *
 * [1108] IP 地址无效化
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
        for(auto c:address)
        {
            if (c == '.')
                ans.append("[.]");
            else
                ans.push_back(c);
        }
        return ans;
    }
};

// int main()
// {
//     string address = "1.1.1.1";
//     Solution s1;
//     cout << address << endl
//          << s1.defangIPaddr(address) << endl;

//     system("pause");
//     return 0;
// }
// @lc code=end

