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

int findBottomLeftValue(TreeNode *root)
{
    queue<TreeNode *> q1;
    q1.push(root);
    int res;
    while (!q1.empty())
    {
        res = q1.front()->val;
        int size = q1.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = q1.front();
            q1.pop();
            if (temp->left != NULL)
                q1.push(temp->left);
            if (temp->right != NULL)
                q1.push(temp->right);
        }
    }
    return res;
}

int main()
{

    system("pause");
    return 0;
}