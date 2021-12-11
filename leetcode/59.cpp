#include <iostream>
using namespace std;
#include <vector>

vector<vector<int>> generateMatrix(int n)
{
    int top = 0, left = 0, right = n - 1, bottom = n - 1;
    vector<vector<int>> res(n, vector<int>(n));
    int num = 1;
    while (num <= n * n)
    {
        for (int i = left; i <= right && num <= n * n; i++)
            res[top][i] = num++;
        top++;
        for (int i = top; i <= bottom && num <= n * n; i++)
            res[i][right] = num++;
        right--;
        for (int i = right; i >= left && num <= n * n; i--)
            res[bottom][i] = num++;
        bottom--;
        for (int i = bottom; i >= top && num <= n * n; i--)
            res[i][left] = num++;
        left++;
    }
    return res;
}

int main()
{

    system("pause");
    return 0;
}
