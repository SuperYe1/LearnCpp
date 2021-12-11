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

ListNode *removeElements(ListNode *head, int val)
{
    if (head == nullptr)
        return nullptr;
    ListNode *pureHead = new ListNode(-1);
    pureHead->next = head;
    ListNode *prev = pureHead;
    while(head != nullptr)
    {
        if(head->val != val)
        {
            prev = head;
            head = head->next;
            continue;
        }
        else
        {
            head = head->next;
            prev->next = head;
            continue;
        }
    }

    return pureHead->next;
}

int main()
{

    system("pause");
    return 0;
}
