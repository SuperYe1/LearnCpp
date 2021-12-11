#include <iostream>
#include <unordered_map>
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

TreeNode *build(vector<int> &preorder, vector<int> &inorder, int preleft,
                int preright, unordered_map<int, int> M, int inleft, int inright)
{
    if (preleft > preright || inleft > inright)
        return nullptr;
    TreeNode *root = new TreeNode(preorder[preleft]);
    int pindex = M[preorder[preleft]];
    root->left = build(preorder, inorder, preleft + 1, pindex - inleft + preleft,
                      M, inleft, pindex - 1);
    root->right = build(preorder, inorder, pindex - inleft + preleft + 1, preright,
                       M, pindex + 1, inright);

    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int prelen = preorder.size();
    int inlen = inorder.size();
    if (prelen != inlen)
        cout << "wrong data" << endl;

    unordered_map<int, int> M;
    for (int i = 0; i < inlen; i++)
    {
        M[inorder[i]] = i;
    }

    return build(preorder, inorder, 0, prelen - 1, M, 0, inlen - 1);
}

int main()
{

    system("pause");
    return 0;
}
