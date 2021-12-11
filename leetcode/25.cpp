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

ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *newHead = head;
    vector<ListNode *> v;
    for (int i = 0; i < k; i++)
    {
        if (head == nullptr)
        {
            return newHead;
        }
        v.push_back(head);
        head = head->next;
    }
    // v[k - 1] = newHead;
    for (int i = k - 1; i > 0; i--)
    {
        v[i]->next = v[i - 1];
    }
    v[0]->next = reverseKGroup(head, k);
    return v[k-1];
}

int main()
{

    system("pause");
    return 0;
}
