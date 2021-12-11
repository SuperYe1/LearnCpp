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

bool check(TreeNode *p, TreeNode *q)
{
    // if (p == nullptr && q == nullptr)
    //     return true;
    // if (p == nullptr || q == nullptr)
    //     return false;
    // return (p->val == q->val) && check(p->left, q->right) && check(p->right, q->left);
    queue<TreeNode *> que;
    que.push(p);
    que.push(q);
    while (!que.empty())
    {
        p = que.front();
        que.pop();
        q = que.front();
        que.pop();
        if (!q && !p)
            continue;
        if ((!q || !p) || (p->val != q->val))
            return false;
        que.push(q->left);
        que.push(p->right);
        que.push(q->right);
        que.push(p->left);
    }
    return true;
}

bool isSymmetric(TreeNode *root)
{
    // return check(root, root);
}
int main()
{

    system("pause");
    return 0;
}
