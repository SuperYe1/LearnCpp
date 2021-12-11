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
    if (head == nullptr)
        return head;
    ListNode *index = head;
    ListNode *index2 = head->next;
    while (index2 != NULL)
    {
        if (index2->val == index->val)
        {
            index2 = index2->next;
        }
        else
        {
            index->next = index2;
            index = index->next;
            index2 = index2->next;
        }
    }
    if (index->next != nullptr && index->val == index->next->val)
        index->next = nullptr;
    return head;
}

int main()
{

    system("pause");
    return 0;
}
