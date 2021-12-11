#include <iostream>
using namespace std;
#include <vector>
//正则表达式匹配
//给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

// '.' 匹配任意单个字符
// '*' 匹配零个或多个前面的那一个元素
// 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

// 说明:
// s 可能为空，且只包含从 a-z 的小写字母。
// p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。

bool isMatch(string s, string p)
{
    if(p[0] == '*')
    {
        if(s[1]!=p[0])
            return false;
            else
                p = p.erase(1, 1);
    }
    int m = s.size();
    int n = p.size();

    auto matches = [&](int i, int j) {
        if (i == 0)
            return false;
        if (p[j - 1] == '.')
            return true;
        return s[i - 1] == p[j - 1];
    };

    vector<vector<int>> dp((m + 1), vector<int>(n + 1));
    dp[0][0] = true;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (p[j - 1] == '*')
            {
                dp[i][j] |= dp[i][j - 2];
                if (matches(i, j - 1))
                {
                    dp[i][j] |= dp[i - 1][j];
                }
            }
            else
            {
                if (matches(i, j))
                    dp[i][j] |= dp[i - 1][j - 1];
            }
        }
    }
    return dp[m][n];
}

int main()
{
    string s = "aa";
    string p = "*a";
    bool c = isMatch(s, p);
    if (c)
        cout << "匹配成功" << endl;
    else
        cout << "匹配失败" << endl;

    system("pause");
    return 0;
}
