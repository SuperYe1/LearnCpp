#include <iostream>
#include <vector>
using namespace std;

vector<int> isfind(vector<vector<char>> &board, string word, int row, int col, vector<vector<int>> &v, char c)
{
    if (row + 1 < board.size() && board[row + 1][col] == c && v[row + 1][col] == 0)
    {
        v[row + 1][col] == 1;
        return {row + 1, col};
    }
    if (row - 1 >= 0 && board[row - 1][col] == c && v[row - 1][col] == 0)
    {
        v[row - 1][col] == 1;
        return {row - 1, col};
    }
    if (col + 1 < board[0].size() && board[row][col + 1] == c && v[row][col + 1] == 0)
    {
        v[row][col + 1] == 1;
        return {row, col + 1};
    }
    if (col - 1 >= 0 && board[row][col - 1] == c && v[row][col - 1] == 0)
    {
        v[row][col - 1] == 1;
        return {row, col - 1};
    }
    return {};
}

bool exist(vector<vector<char>> &board, string word)
{
    int m = board.size();
    int n = board[0].size();


    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int index = 0;
            if (board[i][j] == word[index])
            {
                vector<vector<int>> v(m, vector<int>(n, 0));
                v[i][j] = 1;
                int row = i, col = j;
                while (index < word.size())
                {

                    vector<int> temp = isfind(board, word, row, col, v, word[index + 1]);
                    if (temp.size() != 0)
                    {
                        row = temp[0];
                        col = temp[1];
                        v[row][col] = 1;
                        cout<<row<<" "<<col<<endl;
                    }
                    else
                        break;
                    index++;
                }
                if (index == word.size())
                    return true;
                    cout << "************" << endl;
            }

        }
    }
    return false;
}
int main()
{
    vector<vector<char>> board = {{'C', 'A', 'A'}, {'A', 'A', 'A'}, {'B', 'C', 'D'}};
    string word = "AAB";
    bool b = exist(board, word);
    cout << b << endl;
    system("pause");
    return 0;
}
