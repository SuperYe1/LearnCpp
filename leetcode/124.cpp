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

int maxPathSum(TreeNode *root, int ans)
{
    if (root == nullptr)
        return 0;
    int left = max(0, maxPathSum(root->left, ans));
    int right = max(0, maxPathSum(root->right, ans));
    ans = max(ans, left + right + root->val);
    return max(left, right) + root->val;
}

main()
{
    int ans;

    system("pause");
    return 0;
}
