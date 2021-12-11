#include <iostream>
#include <vector>
using namespace std;

/*
有序链表转换二叉搜索树

给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//快慢指针
// ListNode *getMid(ListNode *left, ListNode *right)
// {
//     ListNode *slow = left;
//     ListNode *fast = left;
//     while (fast != right && fast->next != right)
//     {
//         fast = fast->next->next;
//         slow = slow->next;
//     }
//     return slow;
// }

// TreeNode* build(ListNode *left, ListNode *right)
// {
//     if(left == right)
//     {
//         return NULL;
//     }
//     ListNode *mid = getMid(left, right);
//     TreeNode *root = new TreeNode(mid->val);
//     root->left = build(left, mid);
//     root->right = build(mid->next, right);
//     return root;
// }

// TreeNode *sortedListToBST(ListNode *head)
// {
//     return build(head, (ListNode*)NULL);
// }

//中序构建然后插值
TreeNode *build(ListNode *&head, int left, int right)
{
    if (left > right)
    {
        return nullptr;
    }
    int mid = (left + right + 1) / 2;
    TreeNode *root = new TreeNode();
    root->left = build(head, left, mid - 1);
    root->val = head->val;
    head = head->next;
    root->right = build(head, mid + 1, right);
    return root;
}

TreeNode *sortedListToBST(ListNode *head)
{
    int len = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return build(head, 0, len - 1);
}
int main()
{

    return 0;
}