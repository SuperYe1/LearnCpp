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

bool isPalindrome(ListNode *head)
{
    // if (head == nullptr && head->next == nullptr)
    //     return true;
    ListNode *pre = nullptr;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        ListNode *temp = slow->next;
        if (pre != nullptr)
        {
            slow->next = pre;
        }
        pre = slow;
        fast = fast->next->next;
        slow = temp;
    }
    if (fast != nullptr)
        slow = slow->next;
    while (slow != nullptr)
    {
        if (slow->val != pre->val)
            return false;
        slow = slow->next;
        pre = pre->next;
    }
    return true;
}

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *newH = head;
    head->next = new ListNode(2);
    head = head->next;
    head->next = new ListNode(1);
    head = head->next;
    // head->next = new ListNode(1);
    // head = head->next;
    cout << isPalindrome(newH) << endl;

    system("pause");
    return 0;
}
