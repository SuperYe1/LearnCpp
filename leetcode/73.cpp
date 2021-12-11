#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    // int m = matrix.size();
    // int n = matrix[0].size();
    // vector<int> dp(m + n, 0);
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (matrix[i][j] == 0)
    //         {
    //             if (dp[i] != 1)
    //                 dp[i] = 1;
    //             if (dp[m + j] != 1)
    //                 dp[m+j] = 1;
    //         }
    //     }
    // }
    // for (int i = 0; i < m + n; i++)
    // {
    //     if (dp[i] == 1)
    //     {
    //         if (i < m)
    //         {
    //             for (int j = 0; j < n; j++)
    //                 matrix[i][j] = 0;
    //         }
    //         else
    //         {
    //             for (int j = 0; j < m; j++)
    //                 matrix[j][i - m] = 0;
    //         }
    //     }
    // }

    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < m; i++)
    {
        if (matrix[i][0] == 0)
        {
            for (int j = 0; j < n; j++)
                matrix[i][j] = 0;
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (matrix[0][i] == 0)
        {
            for (int j = 0; j < m; j++)
                matrix[j][i] = 0;
        }
    }
    if (matrix[0][0] == 0)
    {
        for (int i = 1; i < n; i++)
            matrix[0][i] = 0;
    }
}

int main()
{

    system("pause");
    return 0;
}
