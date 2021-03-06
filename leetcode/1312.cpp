#include <iostream>
#include <vector>
using namespace std;

int minInsertions(string s)
{
    int n = s.length();
    if (n == 0)
        return 0;
    vector<vector<int>> dp(n, (vector<int>(n, 0)));
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1];
            else
                dp[i][j] =1+ min(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    return dp[0][n - 1];
}

int main()
{

    system("pause");
    return 0;
}
