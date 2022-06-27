#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*动态规划，暴力求解
int superEggDrop(int k, int n)
{
    vector<vector<int>>dp(n+1,vector<int>(k+1,0));
    for (int i = 1; i < k + 1; i++)
        dp[1][i] = 1;
    for (int i = 1; i < n + 1; i++)
        dp[i][1] = i;
    for (int i = 2; i < n + 1; i++)
    {
        for (int j = 2; j < k + 1; j++)
        {
            vector<int> temp(i+1,INT_MAX);
            for (int l = 1; l < i+1;l++)
            {
                temp[l] = max(dp[l-1][j - 1], dp[i - l][j])+1;
            }
            dp[i][j] = *min_element(temp.begin(), temp.end());
        }
    }
    return dp[n][k];
}
*/

/* 数学逆向思维 */
int superEggDrop(int k, int n)
{
    if (n == 1)
        return 1;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    int ans = 0;
    for (int i = 1; i < k + 1; i++)
        dp[1][i] = 1;
    for (int i = 1; i < n + 1; i++)
        dp[i][1] = i;
    for (int i = 2; i < n + 1; i++)
    {
        for (int j = 1; j < k + 1; j++)
        {
            dp[i][j] = 1 + dp[i - 1][j] + dp[i - 1][j - 1];
        }
        if (dp[i][k] >= n)
        {
            ans = i;
            break;
        }
    }
    return ans;
}

int main()
{
    cout << superEggDrop(3, 22) << endl;
    system("pause");
    return 0;
}