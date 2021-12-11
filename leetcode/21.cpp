#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode *result = new ListNode(-1);
    ListNode *l3 = result;

    while (l1 != nullptr && l2 != nullptr)
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
    if (l1 == nullptr)
        l3->next = l2;
    if (l2 == nullptr)
        l3->next = l1;
    // l3->next = l1 == nullptr ? l2 : l1;
    return result->next;
}

int main()
{
    ListNode *l1 = new ListNode(0);
    ListNode *l2 = new ListNode(0);
    ListNode *temp = new ListNode(0);
    ListNode *temp1 = new ListNode(0);
    l1->val = 1;
    l1->next = temp;

    temp->val = 2;
    // temp->next = new ListNode(4);

    l2->val = 1;
    l2->next = temp1;

    temp1->val = 3;
    temp1->next = new ListNode(4);

    ListNode *l3 = mergeTwoLists(l1, l2);
    // while (l1)
    // {
    //     cout << l1->val << " ";

    //     l1 = l1->next;
    // }
    // cout << endl;
    // while (l2)
    // {
    //     cout << l2->val << " ";

    //     l2 = l2->next;
    // }

    cout << endl;
    while (l3)
    {
        cout << l3->val << " ";

        l3 = l3->next;
    }
    cout << endl;

    system("pause");
    return 0;
}
