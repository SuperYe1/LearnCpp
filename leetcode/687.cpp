#include "oftenUse.hpp"
#include <iostream>
#include <vector>
using namespace std;

int res = 0;
int maxPathSame(TreeNode *node, int path)
{
    int left = path, right = path;
    if(node->left && node->val == node->left->val)
        left = maxPathSame(node->left, path+1);
    if(node->right && node->val == node->right->val)
        right = maxPathSame(node->right, path+1);
    return max(left, right);
}

int longestUnivaluePath(TreeNode *root)
{
    res = 0;
    dfs(root);
    return res;
}
int dfs(TreeNode *node)
{
    if(node == nullptr)
        return 0;
    int left = dfs(node->left);
    int right = dfs(node->right);
    int left1 = 0, right1 = 0;
    if(node->left && node->val == node->left->val)
        left1 = left + 1;
    if(node->right && node->val == node->right->val)
        right1 = right + 1;
    res = max(res, left1 + right1);
    return max(left1, right1);
}

int main()
{

    system("pause");
    return 0;
}