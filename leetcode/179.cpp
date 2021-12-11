#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
179. 最大数

给定一组非负整数 nums，
重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。
*/
bool compString(string a, string b)
{
    return true;
    //return a.size() < b.size() ? (a[i - 1] > b[i]) : (a[i] > b[i - 1]);
}

string largestNumber(vector<int> &nums)
{
    int n = nums.size();
    string ans;
    sort(nums.begin(), nums.end(),
         [](auto &x, auto &y)
         {
             string a = to_string(x);
             string b = to_string(y);
             return a+b>b+a;
         });
    for (int i = 0; i < nums.size();i++)
        ans += to_string(nums[i]);
    return ans[0] == '0' ? "0" :ans ;
}

int main()
{
    vector<int> nums = {34323,3432};
    sort(nums.begin(), nums.end(),
         [](auto &x, auto &y)
         {
             string a = to_string(x);
             string b = to_string(y);
             return compString(a, b);
         });
    for (int i = 0; i < nums.size();i++)
        cout << nums[i] << " ";
    cout << endl;
    cout << largestNumber(nums) << endl;

    return 0;
}