#include <iostream>
#include <vector>
using namespace std;

int maxProduct(vector<int> &nums)
{
    int max = INT_MIN;
    int second = max;
    int n = nums.size();
    for (int i = 0; i < n;i++)
    {
        if(nums[i]>max)
        {
            second = max;
            max = nums[i];
        }
        else if(nums[i]>second)
        {
            second = nums[i];
        }
    }
    return (max - 1) * (second - 1);
}
/*


*/
int main()
{
    vector<int> arr = {4, 6, 4, 4, 5, 1, 0, 6, 9, 2};
    cout << maxProduct(arr) << endl;

    return 0;
}