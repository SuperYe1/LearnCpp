#include "oftenUse.hpp"
#include <iostream>
#include <vector>
using namespace std;

int minStartValue(vector<int> &nums)
{
    int ans = 0;
    int total = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        total += nums[i];
        int temp = 1 - total;
        if(temp >0)
        ans = max(ans,temp);
    }
    return ans < 1 ? 1 : ans;
}
int main()
{

    system("pause");
    return 0;
}