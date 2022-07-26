#include "oftenUse.hpp"
#include <iostream>
#include <vector>
using namespace std;

ListNode *reverseList(ListNode *head)
{
    ListNode *next = NULL;
    ListNode *prev = head;
    ListNode *cur = prev;
    while (prev != NULL)
    {
        prev = cur->next;
        cur->next = next;
        next = cur;
        cur = prev;
    }
    return next;
}

int main()
{

    system("pause");
    return 0;
}