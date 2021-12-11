#include <iostream>
using namespace std;
#include <string.h>
#include <utility>
#include <vector>

class solution
{
    // bool row[9][10];
    // bool col[9][10];
    // bool box[3][3][10];
    // bool value = false;
    // vector<pair<int, int>> spaces;

public:
    void solveSudoku(vector<vector<char>> &board)
    {

        fill(board, 0, 0);
    }

    bool fill(vector<vector<char>> &board, int nrow, int nlist)
    {
        if (nlist == 9)
            return fill(board, nrow + 1, 0);
        if (nrow == 9)
            return true;
        if (board[nrow][nlist] != '.')
            return fill(board, nrow, nlist + 1);
        for (char cr = '0';cr<='9';cr++)
        {
            if (!isuse(board, nrow, nlist, cr))
                continue;
            // {
            // row[nrow][num] = true;
            // col[nlist][num] = true;
            // box[nrow / 3][nlist / 3][num] = true;

            board[nrow][nlist] = cr;
            if (fill(board, nrow, nlist + 1))
                return true;
            board[nrow][nlist] = '.';
            // row[nrow][num] = false;
            // col[nlist][num] = false;
            // box[nrow / 3][nlist / 3][num] = false;
            // }
        }

        return false;
    }

    bool isuse(vector<vector<char>> &board, int row, int col, char c)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == c)
                return false;
            if (board[i][col] == c)
                return false;
            if (board[(row / 3)*3 + i / 3][(col / 3)*3 + i % 3] == c)
                return false;
        }
        return true;
    }
};

int main()
{

    system("pause");
    return 0;
}
