#include <iostream>
#include <vector>
using namespace std;

/*
有效的数独
请你判断一个 9x9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
数独部分空格内已填入了数字，空白格用 '.' 表示。
*/

bool isValidSudoku(vector<vector<char>> &board)
{
    int row[9][9] = {0};
    int column[9][9] = {0};
    int subSudo[3][3][9] = {0};
    for (int i = 0; i < 9;i++)
    {
        for (int j = 0; j < 9;j++)
        {
            char c = board[i][j];
            if(c=='.')
                continue;
            int index = c - '0'-1;
            row[i][index]++;
            column[j][index]++;
            subSudo[i / 3][j / 3][index]++;
            if(row[i][index]>1 ||column[j][index]>1||subSudo[i / 3][j / 3][index]>1)
                return false;
        }
    }
    return true;
}

int main()
{

    return 0;
}