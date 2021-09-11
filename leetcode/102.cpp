#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
102. 二叉树的层序遍历
给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int> > levelOrder(TreeNode *root)
{
    vector<vector<int> > res;
    if (root == NULL)
        return res;
    queue<TreeNode *> q1;

    q1.push(root);
    while (!q1.empty())
    {
        int cum = q1.size();
        res.push_back(vector<int>());
        for (int i = 0; i < cum; i++)
        {
            auto node = q1.front();
            q1.pop();
            res.back().push_back(node->val);
            if (node->left)
                q1.push(node->left);
            if (node->right)
                q1.push(node->right);
        }
    }
    return res;
}

int main()
{

    return 0;
}