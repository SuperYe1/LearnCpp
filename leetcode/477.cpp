#include <iostream>
#include <vector>
using namespace std;

int totalHammingDistance(vector<int> &nums)
{
    int ans = 0, n = nums.size();
    for (int i = 0; i < 30; i++)
    {
        int c = 0;
        for (int val : nums)
        {
            c += (val >> i) & 1;
        }
        ans += c * (n - c);
    }
    return ans;
}
int main()
{

    system("pause");
    return 0;
}

vector<int> findDiagonalOrder(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();
    vector<int> res;
    int i = 0, j = 0;
    bool isTurnUp = true;
    while (i != m - 1 || j != n - 1)
    {
        res.push_back(mat[i][j]);
        if (isTurnUp)
        {
            i--;
            j++;
            if (i < 0 && j < n)
            {
                i = 0;
                isTurnUp = !isTurnUp;
            }
            else if(i < 0 && j == n)
            {
                i = 0;
                j = n - 1;
                isTurnUp = !isTurnUp;
            }
            else if(i > 0 && j == n)
            {
                j = n - 1;
                isTurnUp = !isTurnUp;
            }
        }
        else
        {
            
        }
    }
}