#include <iostream>
#include <vector>
using namespace std;

bool isInterleave(string s1, string s2, string s3)
{
    auto dp = vector<vector<int>>(s1.size() + 1, vector<int>(s2.size() + 1, false));
    int n = s1.size(), m = s2.size(), t = s3.size();
    if (n + m != t)
        return false;
    dp[0][0] = true;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            int p = i + j - 1;
            if (i > 0)
            {
                dp[i][j] |= (dp[i - 1][j] && s1[i - 1] == s3[p]);
            }
            if (j > 0)
            {
                dp[i][j] |= (dp[i][j - 1] && s2[j - 1] == s3[p]);
            }
        }
    }
    return dp[n][m];
}
int main()
{

    system("pause");
    return 0;
}
