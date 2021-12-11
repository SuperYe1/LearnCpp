#include <iostream>
using namespace std;
#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    int n = lists.size();
    if (n == 0)
        return {};
    if (n == 1)
        return lists[0];

    // ListNode *l1 = lists[0];
    ListNode *l1 = nullptr;
    // ListNode *l3 = result;
    for (int i = 0; i < n; i++)
    {
        ListNode *result = new ListNode(-1);
        ListNode *l3 = result;
        ListNode *l2 = lists[i];
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                l3->next = l1;
                l1 = l1->next;
            }
            else
            {
                l3->next = l2;
                l2 = l2->next;
            }
            l3 = l3->next;
        }
        l3->next = l1 == nullptr ? l2 : l1;
        l1 = result->next;
    }
    return l1;
}
int main()
{


        system("pause");
    return 0;
}
