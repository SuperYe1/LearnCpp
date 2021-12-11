#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

long long inorder = (long long)INT_MIN - 1;

bool isValidBST(TreeNode *root)
{
    // if (root == nullptr)
    //     return true;
    // if (!isValidBST(root->left))
    //     return false;
    // if (root->val <= inorder)
    //     return false;
    // inorder = root->val;
    // return isValidBST(root->right);

    stack<TreeNode *> stk;
    while (!stk.empty() || root != nullptr)
    {
        while (root != nullptr)
        {
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        if (root->val <= inorder)
            return false;
        inorder = root->val;
        root = root->right;
    }
    return true;
}

int main()
{

    system("pause");
    return 0;
}
