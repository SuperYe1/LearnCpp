#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

/*
从中序与后序遍历序列构造二叉树
根据一棵树的中序遍历与后序遍历构造二叉树。
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

int post = 0;
unordered_map<int, int> m;

TreeNode *build(int left,int right,vector<int> &inorder, vector<int> &postorder)
{
    if(left > right)
        return NULL;
    int rootVal = postorder[post];
    TreeNode *root = new TreeNode(rootVal);

    int index = m[rootVal];
    post--;
    root->right = build(index + 1, right, inorder, postorder);
    root->left = build(left,index-1,inorder,postorder);
    return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    int treeSize = inorder.size();
    if(treeSize == 0)
        return NULL;
    post = treeSize - 1;
    int idx = 0;
    for(auto &val : inorder)
        m[val] = idx++;
    return build(0, post, inorder, postorder);
}

int main()
{

    return 0;
}