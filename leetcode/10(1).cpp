#include <iostream>
#include <vector>
using namespace std;

bool isMatch(string s, string p)
{
    s = " " + s;
    p = " " + p;
    int m = s.size();
    int n = p.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
                dp[i][j] = dp[i - 1][j - 1];
            else if (p[j - 1] == '*')
            {
                if (s[i - 1] != p[j - 2] && p[j - 2] != '.')
                    dp[i][j] = dp[i][j - 2];
                else
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1] || dp[i][j - 2];
            }
        }
    }
    return dp[m][n];
}

int main()
{
    string s= "aaab";
    cout << s[3] << endl;
    s = " " + s;
    cout << s[3] << endl;


    system("pause");
    return 0;
}
