#include <iostream>
using namespace std;
#include <vector>

int jump(vector<int> &nums)
{
    int n = nums.size(), end = 0,now = 0, step = 0,distance = 0;
    while(end<n-1)
    {
        distance = max(distance,nums[now]+now);
        if(now == end)
        {
            step++;
            end = distance;
        }
        now++;
    }
    return step;
}

int main()
{

    system("pause");
    return 0;
}
