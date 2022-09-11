#include "oftenUse.hpp"
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

void fildArray(int nowheight, int weight, int height,
                vector<vector<string>>& array, TreeNode* node)
{
    if(node == NULL || nowheight >= height || weight < 0 || weight >= pow(2,height)-1)
        return;
    array[nowheight][weight] = to_string(node->val);
    fildArray(nowheight + 1, weight - pow(2, height - nowheight -2), height,
              array, node->left);
    fildArray(nowheight + 1, weight + pow(2, height - nowheight -2), height,
              array, node->right);
    return;
}

vector<vector<string>> printTree(TreeNode *root)
{
    int height = 0;
    queue<TreeNode *> qu;
    qu.push(root);
    while(!qu.empty())
    {
        height++;
        int size = qu.size();
        for(int i = 0; i < size; i++)
        {
            auto temp = qu.front();
            qu.pop();
            if(temp->left)
                qu.push(temp->left);
            if(temp->right)
                qu.push(temp->right);
        }
    }
    int n = pow(2, height) - 1;
    vector<vector<string>> ans(height, vector<string>(n, ""));
    fildArray(0, (n-1)/2, height, ans, root);
    return ans;
}
int main()
{

    system("pause");
    return 0;
}