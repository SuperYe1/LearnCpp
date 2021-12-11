#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0 || n == 1)
        return;
    int rnum = 0, bindex = n - 1, i = 0;
    while (i <= bindex)
    {
        if (nums[i] == 0)
        {
            rnum++;
            if (i != rnum - 1)
                swap(nums[i], nums[rnum - 1]);
            i++;
        }
        else if (nums[i] == 2)
        {
            swap(nums[i], nums[bindex]);
            bindex--;
        }
        else
            i++;
    }
}

int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    // sortColors(nums);
    int n = nums.size();
    // if (n == 0 || n == 1)
    //     return;
    int rnum = 0, bindex = n - 1, i = 0;
    while (i <= bindex)
    {
        if (nums[i] == 0)
        {
            rnum++;
            if (i != rnum - 1)
                swap(nums[i], nums[rnum - 1]);
            i++;
        }
        else if (nums[i] == 2)
        {
            swap(nums[i], nums[bindex]);
            bindex--;
        }
        else
            i++;
    }

    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;

    system("pause");
    return 0;
}
