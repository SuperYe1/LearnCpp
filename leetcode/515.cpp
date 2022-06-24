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

vector<int> largestValues(TreeNode *root)
{
    vector<int> res;
    if (root == nullptr)
        return res;
    queue<TreeNode *> q1;
    q1.push(root);
    int rowMax = INT_MIN;
    while (!q1.empty())
    {
        rowMax = INT_MIN;
        int size = q1.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = q1.front();
            q1.pop();
            rowMax = max(rowMax, temp->val);
            if (temp->left)
                q1.push(temp->left);
            if (temp->right)
                q1.push(temp->right);
        }
        res.push_back(rowMax);
    }
    return res;
}

int main()
{

    system("pause");
    return 0;
}