#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<TreeNode *> generateTrees1(int start, int end)
{
    vector<TreeNode *> trees;
    if (start > end)
        return {NULL};
    for (int i = start; i <= end; i++)
    {
        vector<TreeNode *> leftTrees = generateTrees1(start, i - 1);
        vector<TreeNode *> rightTrees = generateTrees1(i + 1, end);
        for (auto &left : leftTrees)
        {
            for (auto &right : rightTrees)
            {
                TreeNode *currTree = new TreeNode(i);
                currTree->left = left;
                currTree->right = right;
                trees.push_back(currTree);
            }
        }
    }
    return trees;
}

vector<TreeNode *> generateTrees(int n)
{
    if (!n)
        return {};
    return generateTrees1(1, n);
}

int main()
{

    system("pause");
    return 0;
}
