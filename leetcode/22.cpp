#include <iostream>
using namespace std;
#include <vector>

vector<string> generateParenthesis(int n)
{
    if (n == 0)
        return {};
    if (n == 1)
        return {"()"};
    vector<vector<string>> dp(n+1);
    dp[0] = {""};
    dp[1] = {"()"};
    for (int i = 2; i < n+1;i++)
    {
        for (int j =0; j <i;j++)
        {
            for (string str1:dp[j])
            {

                for (string str2:dp[i-j-1])
                {
                    string str = "(" + str1 + ")" + str2;
                    dp[i].push_back(str);
                }
            }
        }
    }
    return dp[n];
}

int main()
{

    system("pause");
    return 0;
}
