#include "oftenUse.hpp"
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> res;
int curVal = 0, maxCount = 0, count = 0;

void updata(int val)
{
    if(val == curVal)
        count++;
    else
    {
        count = 1;
        curVal = val;
    }
    if(count == maxCount)
        res.push_back(curVal);
    if(count>maxCount)
    {
        maxCount = count;
        res = vector<int>{curVal};
    }
}
void findVal(TreeNode *root)
{
    if(!root)
        return;
    findVal(root->left);
    updata(root->val);
    findVal(root->right);
}
vector<int> findMode(TreeNode *root)
{
    findVal(root);
    return res;
}
int main()
{
    system("pause");
    return 0;
}