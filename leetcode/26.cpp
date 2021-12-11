#include <iostream>
using namespace std;
#include <vector>

int removeDuplicates(vector<int> &nums)
{
    if (nums.size() == 0 || nums.size() == 1)
        return nums.size();
    int index = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == nums[i - 1])
            continue;
        else
        {
            nums[index] = nums[i];
            index++;
        }
    }
    return index;
}

int main()
{
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int index = removeDuplicates(nums);
    for (int i = 0; i < index;i++)
    {
        cout << nums[i] << ",";
    }
    cout << endl;

    system("pause");
    return 0;
}
