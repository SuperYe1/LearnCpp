#include <iostream>
#include <vector>
using namespace std;

/*
将有序数组转换为二叉搜索树

给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。
高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。
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

TreeNode *build(vector<int> &nums,int left,int right)
{
    if(left>right)
        return NULL;
    int mid = left + (right - left) / 2;

    TreeNode *root = new TreeNode(nums[mid]);
    root->left = build(nums, left, mid - 1);
    root->right = build(nums, mid + 1, right);
    return root;
}

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    return build(nums, 0, nums.size() - 1);
}

int main()
{

    return 0;
}