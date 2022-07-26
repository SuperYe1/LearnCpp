#include "oftenUse.hpp"
#include <iostream>
#include <vector>
using namespace std;

bool cutNode(TreeNode *node)
{
    if (node == NULL)
        return true;
    bool bl = true, br = true;
    if (node->left)
    {
        bl = cutNode(node->left);
        if (bl)
        {
            delete(node->left);
            node->left = NULL;
        }
    }
    if (node->right)
    {
        br = cutNode(node->right);
        if (br)
        {
            delete(node->right);
            node->right = NULL;
        }
    }
    if (node->val == 0 && bl && br)
        return true;
    else
        return false;
}
TreeNode *pruneTree(TreeNode *root)
{
    bool bl = cutNode(root);
    if (bl)
        return NULL;
    return root;
}

int main()
{

    system("pause");
    return 0;
}