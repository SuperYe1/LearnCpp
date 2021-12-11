#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int cubicmax(vector<int> heights)
{
    stack<int> s;
    s.push(-1);
    int maxarea = 0;
    int n = heights.size();
    for (int i = 0; i < n; i++)
    {
        while (s.top() != -1 && heights[i] <= heights[s.top()])
        {
            int height = heights[s.top()];
            s.pop();
            maxarea = max(maxarea, height * (i - s.top() - 1));
        }
        s.push(i);
    }
    while (s.top() != -1)
    {
        int height = heights[s.top()];
        s.pop();
        maxarea = max(maxarea, height * (n - s.top() - 1));
    }
    return maxarea;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    if (matrix.size() == 0)
        return 0;
    int maxarea = 0;
    vector<int> dp(matrix[0].size(), 0);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            dp[j] = matrix[i][j] == '1' ? dp[j] + 1 : 0;
        }
        maxarea = max(maxarea, cubicmax(dp));
    }
    return maxarea;
}

int main()
{

    system("pause");
    return 0;
}
