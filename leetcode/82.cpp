#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *deleteDuplicates(ListNode *head)
{
    if (head == nullptr || head->next == NULL)
        return head;
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *cur = dummy;
    while (head != NULL && head->next != NULL)
    {
        if (cur->next->val == head->next->val)
        {
            while (head != NULL && head->next != NULL && cur->next->val == head->next->val)
                head = head->next;
            cur->next = head->next;
            head = head->next;
        }
        else
        {
            cur = cur->next;
            head = head->next;
        }
    }

    return dummy->next;
}

int main()
{

    system("pause");
    return 0;
}
