#include <iostream>
using namespace std;
#include <vector>

bool canJump(vector<int> &nums)
{
    // if (nums[0] == 0)
    // {
    //     if (nums.size() == 1)
    //         return true;
    //     return false;
    // }

    // int idx0 = -1;
    // for (int i = 0; i < nums.size() - 1; i++)
    // {
    //     if (nums[i] == 0)
    //     {
    //         idx0 = i;
    //         int max = 0;
    //         for (int j = i - 1; j >= 0; j--)
    //         {
    //             if (nums[j] > i - j)
    //                 break;
    //             if (j == 0)
    //                 return false;
    //         }
    //     }
    // }
    // return true;

    int k = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (i > k) return false;
		k = max(k, i + nums[i]);
	}
	return true;
}
int main()
{

    system("pause");
    return 0;
}
