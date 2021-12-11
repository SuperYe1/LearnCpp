#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *partition(ListNode *head, int x)
{
    ListNode *dummy = new ListNode(-1);
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    dummy->next = head;
    ListNode *cur = dummy;
    while (cur->next != NULL && cur->next->val < x)
    {
        cur = cur->next;
    }
    if (cur->next == NULL)
        return head;
    head = cur->next;
    while (head->next != NULL)
    {
        if (head->next->val >= x)
        {
            head = head->next;
        }
        else
        {
            ListNode *temp;
            temp = cur->next;
            cur->next = head->next;
            head->next = head->next->next;
            cur->next->next = temp;
            cur = cur->next;
        }
    }
    return dummy->next;
}

int main()
{

    system("pause");
    return 0;
}
