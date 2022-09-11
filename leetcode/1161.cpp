#include "oftenUse.hpp"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int maxLevelSum(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    int ans;
    int nowLevel = 0, maxVal = INT_MIN;
    while(!q.empty())
    {
        int n = q.size();
        int temp = 0;
        nowLevel++;
        for(int i = 0; i < n; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            temp += node->val;
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        if(temp>maxVal)
        {
            maxVal = temp;
            ans = nowLevel;
        }
    }
    return ans;
}
int main()
{

    system("pause");
    return 0;
}