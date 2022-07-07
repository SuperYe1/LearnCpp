#ifndef __OFTENUSE__
#define __OFTENUSE__
#include <iostream>
#include <stack>
#include <string.h>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct TriNode
{
    int pass;
    bool isEnd;
    TriNode *next[26];
    TriNode() : pass(0), isEnd(false), next({nullptr}) {}
};

class PrefixTree
{
private:
    TriNode *root;

public:
    PrefixTree();
    ~PrefixTree();
    void add(string str);
    bool findStr(string str);
    int findPrefix(string str);
    void erase(string str);
};
#endif