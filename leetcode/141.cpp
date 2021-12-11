#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head)
{
    if(head == NULL)
    return false;
    ListNode *faster = head;
    ListNode *slower = head;
    while (faster->next != NULL && faster->next->next != NULL)
    {
        faster = faster->next->next;
        slower = slower->next;
        if (faster == slower)
            return true;
    }
    return false;
}

int main()
{

    system("pause");
    return 0;
}
