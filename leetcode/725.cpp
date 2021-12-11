#include <iostream>
#include <vector>
using namespace std;

/*
分隔链表


给你一个头结点为 head 的单链表和一个整数 k ，请你设计一个算法将链表分隔为 k 个连续的部分。
每部分的长度应该尽可能的相等：任意两部分的长度差距不能超过 1 。这可能会导致有些部分为 null 。
这 k 个部分应该按照在链表中出现的顺序排列，并且排在前面的部分的长度应该大于或等于排在后面的长度。
返回一个由上述 k 部分组成的数组。

*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

vector<ListNode *> splitListToParts(ListNode *head, int k)
{
    ListNode *temp = head;
    ListNode *pre = head;
    vector<ListNode *> res(k, NULL);
    if (head)
        return res;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    temp = head;
    int num = len / k;
    int resd = len % k;
    for (int i = 0; i < k; i++)
    {
        res[i] = temp;
        int temLen = resd-- > 0 ? num + 1 : num;
        for (int j = 0; j < temLen; j++)
        {
            pre = temp;
            temp = temp->next;
        }

        if (pre)
            pre->next = NULL;
    }
    return res;
}

int main()
{

    return 0;
}