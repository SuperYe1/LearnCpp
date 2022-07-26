#include "oftenUse.hpp"
#include <iostream>
#include <vector>
using namespace std;

int arrayNesting(vector<int> &nums)
{
    int len = nums.size();
    int res = 0, index = 1;
    vector<int> dp(len, 0);
    for (int i = 0; i < len;i++)
    {
        if(dp[i]!=0)
            continue;
        dp[i] = index;
        int tempLen = 1;
        int temp = nums[i];
        while(temp!=i)
        {
            dp[temp] = index;
            temp = nums[temp];
            tempLen++;
        }
        index++;
        res = max(res, tempLen);
    }
    return res;
}

int main()
{

    system("pause");
    return 0;
}