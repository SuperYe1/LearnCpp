/*
 * @lc app=leetcode.cn id=508 lang=cpp
 *
 * [508] 出现次数最多的子树元素和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 */
#include <iostream>
#include <vector>
#include <unordered_map>
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


class Solution
{
public:
    unordered_map<int, int> map;
    int findValTreeSum(TreeNode *root)
    {
        if(root == NULL)
            return 0;
        int leftVal = findValTreeSum(root->left);
        int rightVal = findValTreeSum(root->right);
        map[leftVal + root->val + rightVal]++;
        return leftVal + root->val + rightVal;
    }
    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        findValTreeSum(root);
        vector<int> result;
        result.push_back(1);
        int maxAppear = 0;
        for(auto it:map)
        {
            if(it.second<maxAppear)
                continue;
            else if(it.second >maxAppear)
            {
                result.clear();
                maxAppear = it.second;
            }
            result.push_back(it.first);
        }
        return result;
    }
};

int main()
{
    
    
    system("pause");
    return 0;
}
// @lc code=end
