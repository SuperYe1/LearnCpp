#include "oftenUse.hpp"
#include <iostream>
#include <vector>
using namespace std;

TreeNode *trimBST(TreeNode *root, int low, int high)
{
    while (root && (root->val < low || root->val > high))
    {
        if (root->val < low)
            root = root->right;
        else
            root = root->left;
    }
    if (root == nullptr)
        return nullptr;
     TreeNode *temp = root;
    while(temp->left != nullptr )
    {
        if(temp->left->val < low)
            temp->left = temp->left->right;
        else
            temp = temp->left;
    }
    temp = root;
    while(temp->right != nullptr)
    {
        if(temp->right->val > high)
            temp->right = temp->right->left;
        else
            temp = temp->right;
    }
    return root;
}
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(1);

    root = trimBST(root, 3, 4);
    system("pause");
    return 0;
}