#include "oftenUse.hpp"
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int widthOfBinaryTree(TreeNode *root)
{
    queue<pair<TreeNode *, unsigned long long>> qu;
    int res = 0;
    qu.push({root, 1L});
    while (!qu.empty())
    {
        unsigned long long left = 0, right = 0;
        int n = qu.size();
        for (int i = 0; i < n; i++)
        {
            auto temp = qu.front();
            qu.pop();
            left = (left == 0 ? temp.second : left);
            right = temp.second;
            if (temp.first->left)
            {
                qu.push({temp.first->left, 2*temp.second});
            }
            if (temp.first->right)
            {
                qu.push({temp.first->right, 2*temp.second + 1});
            }
        }
        res = max(res, (int)(right - left + 1));
    }
    return res;
}
int main()
{

    system("pause");
    return 0;
}