#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

/*
路径总和 III

给定一个二叉树的根节点 root ，和一个整数 targetSum ，
求该二叉树里节点值之和等于 targetSum 的 路径 的数目。

路径 不需要从根节点开始，也不需要在叶子节点结束，
但是路径方向必须是向下的（只能从父节点到子节点）。

*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};
// int rootSum(TreeNode* root,int targetSum)
// {
//     if(!root)
//         return 0;
//     int ret = 0;
//     if(root->val==targetSum)
//         ret++;
//     ret += rootSum(root->left, targetSum - root->val);
//     ret += rootSum(root->right, targetSum - root->val);
//     return ret;
// }

// int pathSum(TreeNode *root, int targetSum)
// {
//     if(!root)
//         return 0;
//     int ret = 0;
//     ret = rootSum(root, targetSum);
//     ret += pathSum(root->left, targetSum);
//     ret += pathSum(root->right, targetSum);
// }

unordered_map<long long, int> prefix;

int dfs(TreeNode *root, long long cur,int targetsum)
{
    if(!root)
        return 0;
    int ret = 0;
    cur += root->val;
    if(prefix.count(cur-targetsum))
        ret = prefix[cur - targetsum];
    prefix[cur]++;

    ret += dfs(root->left, cur, targetsum);
    ret += dfs(root->right, cur, targetsum);
    prefix[cur]--;
    return ret;
}

int pathSum(TreeNode *root, int targetSum)
{
    if(!root)
        return 0;
    prefix[0] = 1;
    return dfs(root,0, targetSum);
}

int main()
{

    return 0;
}