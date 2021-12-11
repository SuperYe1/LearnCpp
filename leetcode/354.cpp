#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int maxEnvelopes(vector<vector<int>> &envelopes)
{
    if (envelopes.size() == 0)
        return 0;
    vector<int> dp(envelopes.size(), 1);
    int res = 0;
    sort(envelopes.begin(), envelopes.end(), [](const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
    });
    for (int i = 0; i < envelopes.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (envelopes[j][1] < envelopes[i][1])
                dp[i] = max(dp[i], dp[j]+1);
        }
        res = max(res, dp[i]);
    }
    return res;
}

int main()
{

    system("pause");
    return 0;
}
