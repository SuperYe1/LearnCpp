#include <iostream>
using namespace std;
#include <vector>
bool isValidSudoku(vector<vector<char>> &board)
{
    vector<vector<int>> row(9, vector<int>(9, 0));
    vector<vector<int>> col(9, vector<int>(9, 0));
    vector<vector<int>> box(9, vector<int>(9, 0));
    int n = board.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == '.')
                continue;
            int index = (i / 3) * 3 + j / 3;
            int val = board[i][j] - '1';
            if (box[index][val] == 0 && row[i][val] == 0 && col[j][val] == 0)
            {
                row[i][val]++;
                col[j][val]++;
                box[index][val]++;
            }
            else
                return false;
        }
    }
    return true;
}

int main()
{

    system("pause");
    return 0;
}
