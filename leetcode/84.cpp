#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    //暴力
    // int res = 0;
    // for(int i = 0; i < heights.size(); i++)
    // {
    //     int left = i-1,right = i+1;
    //     for (left = i - 1; left >= 0;left--)
    //     {
    //         if(heights[left] < heights[i])
    //             break;
    //     }
    //     for(right = i+1; right < heights.size(); right++)
    //     {
    //         if(heights[right] < heights[i])
    //             break;
    //     }
    //     int len = right - left - 1;
    //     res = max(res, len * heights[i]);
    // }
    // return res;

    //单调栈
    stack<int> s;
    int n = heights.size();
    if (n == 1)
        return heights[0];
    if (n == 0)
        return 0;
    int res = 0;
    vector<int> v;
    v.push_back(0);
    for (int i = 0; i < n; i++)
    {
        v.push_back(heights[i]);
    }
    v.push_back(0);
    n = v.size();
    heights = v;
    s.push(0);
    for (int i = 1; i < n; i++)
    {
        while (heights[i] < heights[s.top()])
        {
            int height = heights[s.top()];
            s.pop();
            int width = i - s.top() - 1;
            res = max(res, height * width);
        }
        s.push(i);
    }
    return res;
}

int main()
{

    system("pause");
    return 0;
}
