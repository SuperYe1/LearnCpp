#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st;
    vector<int> left(n), right(n,n);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            right[st.top()] = i;
            st.pop();
        }
        left[i] = (st.empty() ? -1 : st.top());
        st.push(i);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, heights[i]*(right[i]-left[i]-1));
    }
    return ans;
}

int main()
{

    system("pause");
    return 0;
}