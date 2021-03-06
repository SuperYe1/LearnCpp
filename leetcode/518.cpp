#include <iostream>
#include <vector>
using namespace std;

int change(int amount, vector<int> &coins)
{

    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int coin : coins)
    {
        for (int i = coin; i < dp.size(); i++)
        {
            dp[i] += dp[i - coin];
        }
    }
    return dp[amount];
}

int main()
{

    system("pause");
    return 0;
}
