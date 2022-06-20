/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 */
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution
{
public:
    // TreeNode *end;
    // void flatten(TreeNode *root)
    // {
    //     end = nullptr;
    //     if (root == nullptr)
    //         return;
    //     if (root->left == nullptr && root->right == nullptr)
    //     {
    //         end = root;
    //         return;
    //     }
    //     flatten(root->left);
    //     if (end!=nullptr)
    //     {
    //         end->right = root->right;
    //         root->right = root->left;
    //         root->left = nullptr;
    //         return flatten(end);
    //     }
    //     return flatten(root->right);
    // }

    //进阶O（1）空间复杂度做法
    void flatten(TreeNode *root)
    {
        TreeNode *cur = root;
        while (cur != nullptr)
        {
            if (cur->left != nullptr)
            {
                TreeNode *next = cur->left;
                TreeNode *pre = next;
                while (pre->right != nullptr)
                    pre = pre->right;
                pre->right = cur->right;
                cur->right = next;
                cur->left = nullptr;
            }
            cur = cur->right;
        }
    }
};
// @lc code=end
