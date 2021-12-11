#include<iostream>
using namespace std;
#include <vector>

bool isValid(int row, int col, vector<string> &combine)
{
    int n = combine.size();
    for (int i = 0; i < row; i++)
    {
        if (combine[i][col] == 'Q')
            return false;
    }
    for (int i = 0; i < col; i++)
    {
        if (combine[row][i] == 'Q')
            return false;
    }
    int i = row - 1, j = col - 1;
    while (i >= 0 && j >= 0)
    {
        if (combine[i][j] == 'Q')
            return false;
        i--;
        j--;
    }
    i = row - 1;
    j = col + 1;
    while (i >= 0 && j < n)
    {
        if (combine[i][j] == 'Q')
            return false;
        i--;
        j++;
    }
    return true;
}

void backTrade(int row, int &res, vector<string> &combine)
{
    int n = combine.size();
    if (row == n)
    {
        res++;
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        if (!isValid(row, i, combine))
            continue;
        combine[row][i] = 'Q';
        backTrade(row + 1, res, combine);
        combine[row][i] = '.';
    }
}

int totalNQueens(int n)
{
    int res = 0;
    vector<string> combine(n, string(n, '.'));
    backTrade(0, res, combine);
    return res;
}
int main()
{


    system("pause");
    return 0;
}
