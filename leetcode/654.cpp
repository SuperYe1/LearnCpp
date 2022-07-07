#include "oftenUse.hpp"
#include <iostream>
#include <vector>
using namespace std;

int maxIndex(vector<int> &nums, int left, int right)
{
    int maxIndex = left;
    for (int i = left; i < right; i++)
    {
        if (nums[i] > nums[maxIndex])
            maxIndex = i;
    }
    return maxIndex;
}

TreeNode *createTree(vector<int> &nums,int left,int right)
{
    if(left==right)
        return NULL;
    int maxi = maxIndex(nums,left,right);
    TreeNode *node = new TreeNode(nums[maxi]);
    node->left = createTree(nums,left,maxi);
    node->right = createTree(nums,maxi+1,right);
    return node;
}
TreeNode *constructMaximumBinaryTree(vector<int> &nums)
{
    return createTree(nums, 0, nums.size());
}
int main()
{

    system("pause");
    return 0;
}