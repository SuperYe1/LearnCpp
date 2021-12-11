#include <iostream>
using namespace std;
#include <vector>
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    if (row == 0 || col == 0)
        return {};
    int total = row * col;
    int left = 0, top = 0, right = col - 1, bottom = row - 1;
    vector<int> res;
    while(total>0)
    {
        for (int i = left; i <= right && total > 0;i++)
        {
            res.push_back(matrix[top][i]);
            total--;
        }
        top++;
        for (int i = top; i <= bottom && total > 0;i++)
        {
            res.push_back(matrix[i][right]);
            total--;
        }
        right--;
        for (int i = right; i >= left && total > 0;i--)
        {
            res.push_back(matrix[bottom][i]);
            total--;
        }
        bottom--;
        for (int i = bottom; i >= top && total > 0;i--)
        {
            res.push_back(matrix[i][left]);
            total--;
        }
        left++;
    }
    return res;
}

int main()
{

    system("pause");
    return 0;
}
