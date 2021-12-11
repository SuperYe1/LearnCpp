#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int kthLargestValue(vector<vector<int>> &matrix, int k)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> pre(m + 1, vector<int>(n + 1));
    vector<int> res;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            pre[i][j] = pre[i - 1][j - 1] ^ pre[i][j - 1] ^ pre[i - 1][j] ^ matrix[i-1][j-1];
            res.push_back(pre[i][j]);
        }
    }
    sort(res.begin(), res.end(), greater<int>());
    return res[k - 1];
}

int main()
{
    int i = 5;
    int j = 2;
    cout << (i ^ j) << endl;

    system("pause");
    return 0;
}
