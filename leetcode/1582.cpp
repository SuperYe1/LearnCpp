#include "oftenUse.hpp"
#include <iostream>
#include <vector>
using namespace std;

int numSpecial(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();
    int ans = 0;
    vector<int> row(m);
    vector<int> col(n);
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(mat[i][j])
            {
                row[i]++;
                col[j]++;
            }
        }
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(mat[i][j] && row[i] == 1 && col[j] == 1)
                ans++;
        }
    }
    return ans;
}


int main()
{

    system("pause");
    return 0;
}