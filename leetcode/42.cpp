#include <iostream>
using namespace std;
#include <vector>

int trap(vector<int> &height)
{
    int ans = 0;
    int n = height.size();
    int left = 0;
    int leftMax = 0;
    int right = n - 1;
    int rightMax = 0;
    while (left < right)
    {
        if (height[left] < height[right])
        {
            height[left] >= leftMax ? (leftMax = height[left]) : (ans = ans + leftMax - height[left]);
            left++;
        }
        else
        {
            height[right] >= rightMax ? (rightMax = height[right]) : (ans = ans + rightMax - height[right]);
            right--;
        }
    }
    return ans;
}

int main()
{
    vector<int> height = {4, 2, 3};
    int ans = 0;
    int n = height.size();
    int left = 0;
    int leftMax = 0;
    int right = n - 1;
    int rightMax = 0;
    while (left < right)
    {
        if (height[left] < height[right])
        {
            height[left] >= leftMax ? (leftMax = height[left]) : (ans = ans + leftMax - height[left]);
            left++;
        }
        else
        {
            height[right] >= rightMax ? (rightMax = height[right]) : (ans = ans + rightMax - height[right]);
            right--;
        }
    }

    cout << ans << endl;

    system("pause");
    return 0;
}
