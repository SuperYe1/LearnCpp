#include "oftenUse.hpp"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class CBTInserter
{
private:
    TreeNode *root;
    vector<TreeNode *> rootList;

public:
    CBTInserter(TreeNode *root)
    {
        this->root = root;
        queue<TreeNode *> qu;
        qu.push(root);
        while (!qu.empty())
        {
            int len = qu.size();
            TreeNode *temp = qu.front();
            qu.pop();
            rootList.push_back(temp);
            if (temp->left != NULL)
                qu.push(temp->left);
            if (temp->right != NULL)
                qu.push(temp->right);
        }
    }

    int insert(int val)
    {
        
        TreeNode *node = new TreeNode(val);
        rootList.push_back(node);
        int len = rootList.size();
        if (len % 2)
            rootList[len / 2]->left = node;
        else
            rootList[len / 2]->right = node;
        return rootList[len / 2]->val;
    }

    TreeNode *get_root()
    {
        return this->root;
    }
};
int main()
{

    system("pause");
    return 0;
}