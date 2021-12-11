#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseBetween(ListNode *head, int left, int right)
{
    ListNode *dummyHead = new ListNode(-1);
    ListNode *prev = dummyHead;
    dummyHead->next = head;
    if (left == right)
        return dummyHead->next;
    for (int i = 1; i < left; i++)
        prev = prev->next;

    ListNode *cur = prev->next;
    ListNode *cnext;
    for (int i = left; i < right; i++)
    {
        cnext = cur->next;
        cur->next = cnext->next;
        cnext->next = prev->next;
        prev->next = cnext;
    }
    return dummyHead->next;
}

int main()
{

    system("pause");
    return 0;
}
