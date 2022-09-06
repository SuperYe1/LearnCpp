#ifndef __OFTENUSE__
#define __OFTENUSE__
#include <iostream>
#include <stack>
#include <string.h>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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
    TriNode() : pass(0), isEnd(false), next{nullptr} {}
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