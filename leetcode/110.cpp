#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool res = true;
int treeHeight(TreeNode *root)
{
    if(root == nullptr || !res)
        return 0;
    int left = treeHeight(root->left);
    int right = treeHeight(root->right);
    if(abs(left-right)>1)
        res = false;
    return max(left, right) + 1;
}
bool isBalanced(TreeNode *root)
{
    int height = treeHeight(root);
    return res;
}

int main()
{

    system("pause");
    return 0;
}