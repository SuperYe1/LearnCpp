#include "oftenUse.hpp"
#include <iostream>
#include <vector>
using namespace std;

void insertNode(TreeNode *root, TreeNode *node)
{
    if (root->val > node->val)
    {
        if(root->left)
            insertNode(root->left, node);
        else
            root->left = node;
    }
    else
    {
        if(root->right)
            insertNode(root->right, node);
        else
            root->right = node;
    }
}
TreeNode *bstFromPreorder(vector<int> &preorder)
{
    TreeNode *root = new TreeNode(preorder[0]);
    for(int i = 1; i < preorder.size(); i++)
    {
        TreeNode *node = new TreeNode(preorder[i]);
        insertNode(root, node);
    }
    return root;
}
int main()
{

    system("pause");
    return 0;
}