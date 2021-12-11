#include <iostream>
using namespace std;
#include <vector>

bool isMatch(string s, string p)
{
    if (s.size() == 0 && p == "*")
        return true;
    int m = s.size();
    int n = p.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    dp[0][0] = true;
    for (int i = 1; i <= n; i++)
    {
        if (p[i - 1] == '*')
            dp[0][i] = true;
        else
            break;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (p[j - 1] == '*')
                dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
            else if (p[j - 1] == '?' || s[i - 1] == p[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
        }
    }
    return dp[m][n];
}

int main()
{

    system("pause");
    return 0;
}
