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

void recoverTree(TreeNode *root)
{
    if (root == nullptr)
        return;
    recoverTree(root->left);
    TreeNode *temp = root;
}

int main()
{

    system("pause");
    return 0;
}
