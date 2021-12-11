#include <iostream>
#include <queue>
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

//广度搜索 队列
int maxDepth(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    queue<TreeNode *> q;
    int depth = 1;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
        }
        depth++;
    }
    return depth;
}

//迭代

int maxDepth(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}


int main()
{

    system("pause");
    return 0;
}
