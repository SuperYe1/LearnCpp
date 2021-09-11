#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

/*
103. 二叉树的锯齿形层序遍历
给定一个二叉树，返回其节点值的锯齿形层序遍历。
（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
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

vector<vector<int> > zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int> > res;
    if (root == NULL)
        return res;
    queue<TreeNode *> q1;
    bool isSeq = true;
    q1.push(root);
    while (!q1.empty())
    {
        deque<int> d1;
        int cum = q1.size();
        for (int i = 0; i < cum; i++)
        {
            auto node = q1.front();
            q1.pop();
            if(isSeq)
                d1.push_back(node->val);
            else
                d1.push_front(node->val);
            if (node->left)
                q1.push(node->left);
            if (node->right)
                q1.push(node->right);
        }
        isSeq = !isSeq;
        res.push_back(vector<int>(d1.begin(), d1.end()));
    }
    return res;
}

int main()
{

    return 0;
}