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
ListNode *swapPairs(ListNode *head)
{
    // ListNode *l2 = head;
    // int num = 0;
    // vector<ListNode *> v;
    // while (l2)
    // {
    //     v.push_back(l2);
    //     num++;
    //     l2 = l2->next;
    // }
    // if (head == nullptr)
    //     return {};
    // if (num == 1)
    //     return v[0];

    // if (num % 2 == 0)
    // {
    //     for (int i = 0; i < num; i++)
    //     {
    //         if (i == num - 2)
    //         {
    //             v[i]->next = nullptr;
    //         }
    //         else if ((i + 1) % 2 == 1)
    //         {
    //             v[i]->next = v[i + 3];
    //         }
    //         else
    //         {
    //             v[i]->next = v[i - 1];
    //         }
    //     }
    // }
    // else
    // {
    //     for (int i = 0; i < num - 1; i++)
    //     {
    //         if (i == num - 3)
    //         {
    //             v[i]->next = v[i + 2];
    //         }
    //         else if ((i + 1) % 2 == 1)
    //         {
    //             v[i]->next = v[i + 3];
    //         }
    //         else
    //         {
    //             v[i]->next = v[i - 1];
    //         }
    //     }
    // }
    // return v[1];

    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    ListNode *newHead = head->next;
    head->next = swapPairs(newHead->next);
    newHead->next = head;
    return newHead;
}
int main()
{
    ListNode *head = new ListNode(1);
    ListNode *temp = new ListNode(0);
    head->next = temp;

    temp->val = 2;
    temp->next = new ListNode(3);
    temp = temp->next;

    temp->val = 3;
    temp->next = new ListNode(0);
    temp = temp->next;

    temp->val = 4;
    temp->next = new ListNode(5);
    temp = temp->next;

    temp->val = 5;
    temp->next = new ListNode(6);

    // ListNode *l2 = head;
    // int num = 0;
    // vector<ListNode *> v;
    // while (l2)
    // {
    //     v.push_back(l2);
    //     num++;
    //     l2 = l2->next;
    // }

    // if (num % 2 == 0)
    // {
    //     for (int i = 0; i < num; i++)
    //     {
    //         if (i == num - 2)
    //         {
    //             v[i]->next = nullptr;
    //         }
    //         else if ((i + 1) % 2 == 1)
    //         {
    //             v[i]->next = v[i + 3];
    //         }
    //         else
    //         {
    //             v[i]->next = v[i - 1];
    //         }
    //     }
    // }
    // else
    // {
    //     for (int i = 0; i < num - 1; i++)
    //     {
    //         if (i == num - 3)
    //         {
    //             v[i]->next = v[i+2];
    //         }
    //         else if ((i + 1) % 2 == 1)
    //         {
    //             v[i]->next = v[i + 3];
    //         }
    //         else
    //         {
    //             v[i]->next = v[i - 1];
    //         }
    //     }
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
    ListNode *result = swapPairs(head);
    while (result)
    {
        cout << result->val;
        result = result->next;
    }
    cout << endl;

    system("pause");
    return 0;
}
