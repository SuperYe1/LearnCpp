#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    if (nums.size() <= 2)
        return nums.size();
    int index = nums.size() - 1;
    int cnt = 1;
    while (index > 0)
    {
        index--;
        if(nums[index]==nums[index+1])
        {
            cnt++;
            if(cnt>2)
            {
                nums.erase(nums.begin() + index);
                cnt--;
            }
        }
        else
        {
            cnt = 1;
        }
    }
    return nums.size();
}

int main()
{

    system("pause");
    return 0;
}
