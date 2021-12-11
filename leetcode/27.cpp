#include <iostream>
using namespace std;
#include <vector>

int removeElement(vector<int> &nums, int val)
{
    int index = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == val)
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
    vector<int> nums = {3, 2, 2, 3};
    int val;
    int index = removeElement(nums, 3);
    for (int i = 0; i < index;i++)
        cout << nums[i] << ",";
    cout << endl;
    system("pause");
    return 0;
}
