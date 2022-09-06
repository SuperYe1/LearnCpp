#include<iostream>
#include"oftenUse.hpp"
//using namespace std;

/*


*/
unordered_map<string, TreeNode *> mp;
unordered_set<TreeNode *> ans;

string fildStrTree(TreeNode *node)
{
    string res;
    if (node == nullptr)
        return " ";
    else
        res = to_string(node->val) + "(" + fildStrTree(node->left) + ")" + "(" + fildStrTree(node->right) + ")";
    if(mp.count(res))
        ans.insert(mp[res]);
    else
        mp[res] = node;
    return res;
}
vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
{
    fildStrTree(root);
    return {ans.begin(),ans.end()};
}
int main()
{

    cout << "hello" << endl;
    return 0;
}