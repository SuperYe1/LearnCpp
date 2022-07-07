#include <iostream>
#include <vector>
using namespace std;

/*
113. 路径总和 II
给你二叉树的根节点 root 和一个整数目标和 targetSum ，
找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。

叶子节点 是指没有子节点的节点。
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> ans;
void insertNum(TreeNode *root, vector<int> &temp, int targetSum)
{
    if(root == NULL)
        return;
    temp.push_back(root->val);
    if (root->left == NULL &&
        root->right == NULL && targetSum == root->val)
    {
        ans.push_back(temp);
    }
    insertNum(root->left, temp, targetSum - root->val);
    insertNum(root->right, temp, targetSum - root->val);
    temp.pop_back();
}
vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    vector<int> temp;
    insertNum(root, temp, targetSum);
    return ans;
}

int main()
{

    return 0;
}