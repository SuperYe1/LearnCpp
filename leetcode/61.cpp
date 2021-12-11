#include <iostream>
using namespace std;
#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){};
};

ListNode *rotateRight(ListNode *head, int k)
{
    if(head == NULL || head->next == NULL)
        return head;
    ListNode *tail = head;
    int n;
    for (n = 1; tail->next != NULL;n++)
    {
        tail = tail->next;
    }
    tail->next = head;
    k =n- k % n;

    while(k>0)
    {
        tail = tail->next;
        k--;
    }
    ListNode *newHead = tail->next;
    tail->next = NULL;
    return newHead;
}
int main()
{

    system("pause");
    return 0;
}
