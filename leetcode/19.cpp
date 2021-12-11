#include <iostream>
using namespace std;
#include <vector>

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *l2 = head;
    int num = 0;
    vector<ListNode *> v;
    while (l2)
    {
        v.push_back(l2);
        num++;
        l2 = l2->next;
    }
    if (num == n)
        return head->next;
    else if (n == 1)
        v[num - 2]->next = nullptr;
    else
        v[num - n - 1]->next = v[num - n + 1];
    return v[0];
}
int main()
{
    ListNode *head = new ListNode(1);
    ListNode *temp = new ListNode(0);
    head->next = temp;

    temp->val = 2;
    temp->next = new ListNode(0);
    temp = temp->next;

    temp->val = 3;
    temp->next = new ListNode(0);
    temp = temp->next;

    temp->val = 4;
    temp->next = new ListNode(5);

    int n = 2;

    cout << head->val << " " << (head->next)->val << " " << (head->next->next)->val
         << " " << (head->next->next->next)->val << " " << (head->next->next->next->next)->val
         << endl;

    ListNode *l1 = new ListNode(-1);
    ListNode *l2 = head;
    int num = 0;
    vector<ListNode *> v;
    while (l2)
    {
        v.push_back(l2);
        num++;
        l2 = l2->next;
    }
    vector<ListNode *> v1 = v;
    for (int i = 0; i < v.size(); i++)
    {
        while (v1[i])
        {

            cout << v1[i]->val;
            v1[i] = v1[i]->next;
        }
        cout << endl;
    }
    if (num == n)
        head = v[0];
    else if (n == 1)
        v[num - 2]->next = nullptr;
    else
        v[2]->next = v[4];
    cout << num << " "<<n<< endl;
    // v[2]->next = v[4];

    for (int i = 0; i < v.size(); i++)
    {
        while (v[i])
        {

            cout << v[i]->val;
            v[i] = v[i]->next;
        }
        cout << endl;
    }

    // ListNode *l = head;
    // while (l)
    // {
    //     cout << l->val;
    //     l = l->next;
    // }

    // for (int i = 0; i < v.size(); i++)
    // {
    //     while (v[i])
    //     {

    //         cout << v[i]->val;
    //         v[i] = v[i]->next;
    //     }
    //     cout << endl;
    // }

    // ListNode *l = removeNthFromEnd(head, n);

    // while (l)
    // {
    //     cout << l->val;
    //     l = l->next;
    // }
    system("pause");
    return 0;
}
