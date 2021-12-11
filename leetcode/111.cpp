#include <iostream>
#include <queue>
#include <stack>
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

int minDepth(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int depth = 1;
    queue<TreeNode *> s;
    s.push(root);
    while (!s.empty())
    {
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            TreeNode *node = s.front();
            s.pop();
            if (node->left == nullptr && node->right == nullptr)
            {
                return depth;
            }
            if (node->left != nullptr)
                s.push(node->left);
            if (node->right != nullptr)
                s.push(node->right);
        }
        depth++;
    }
    return depth;
}

int main()
{

    system("pause");
    return 0;
}
