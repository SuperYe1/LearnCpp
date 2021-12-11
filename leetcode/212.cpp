#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

/*
单词搜索 II

给定一个 m x n 二维字符网格 board 和一个单词（字符串）列表 words，
找出所有同时在二维网格和字典中出现的单词。

单词必须按照字母顺序，通过 相邻的单元格 内的字母构成，
其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
同一个单元格内的字母在一个单词中不允许被重复使用。
*/
struct TrieNode
{
    string word;
    unordered_map<char, TrieNode *> children;
    TrieNode()
    {
        this->word = "";
    }
};

void insertTrie(TrieNode *root, const string &word)
{
    TrieNode *node = root;
    for (auto c : word)
    {
        if (!node->children.count(c))
        {
            node->children[c] = new TrieNode();
        }
        node = node->children[c];
    }
    node->word = word;
}

int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool dfs(vector<vector<char>> &board, int x, int y, TrieNode *root, vector<string> &res)
{
    char ch = board[x][y];
    if (!root->children.count(ch))
        return false;
    root = root->children[ch];
    if (root->word.size() > 0)
    {
        res.push_back(root->word);
        root->word = "";
    }
    board[x][y] = '#';

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dirs[i][0];
        int ny = y + dirs[i][1];
        if (nx >= 0 && ny >= 0 && nx < board.size() && ny < board[0].size())
        {
            if (board[nx][ny] != '#')
                dfs(board, nx, ny, root, res);
        }
    }
    board[x][y] = ch;
    return true;
}

vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
{
    TrieNode *root = new TrieNode();
    set<string> res;
    vector<string> ans;
    for (auto word : words)
    {
        insertTrie(root, word);
    }

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            dfs(board, i, j, root, ans);
        }
    }
    return ans;
}

int main()
{

    return 0;
}