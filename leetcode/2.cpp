#include <iostream>
using namespace std;
#include <cmath>
#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int sum = 0;
        int i = 0;
        ListNode *temp1 = new ListNode(0);
        temp1 = l1;
        while (temp1->next != nullptr)
        {
            sum = sum + (temp1->val) * (pow(10, i));
            i++;
            temp1 = temp1->next;
        }
        temp1 = l2;
        i = 0;
        while (temp1->next != nullptr)
        {
            sum = sum + (temp1->val) * (pow(10, i));
            i++;
            temp1 = temp1->next;
        }

        ListNode *l3 = new ListNode(0);
        temp1 = l3;
        int j = 1;
        for (int i = sum; (i / 10) != 0; i = i / 10)
        {
            j++;
        }
        for (int i = 0; i < j; i++)
        {
            temp1->val = sum % 10;
            temp1->next = new ListNode(0);
            temp1 = temp1->next;
            temp1->next = nullptr;
            sum = sum / 10;
        }
        return l3;
    }
};

void test01()
{
    Solution s1;
    ListNode *l1 = new ListNode(0);
    ListNode *l2 = new ListNode(0);
    ListNode *temp = new ListNode(0);
    ListNode *temp1 = new ListNode(0);
    l1->val = 2;
    l1->next = temp;

    temp->val = 4;
    temp->next = new ListNode(0);
    temp = temp->next;

    temp->val = 3;
    temp->next = new ListNode(0);
    // temp = temp->next;

    l2->val = 5;
    l2->next = temp1;

    temp1->val = 6;
    temp1->next = new ListNode(0);
    temp1 = temp1->next;

    temp1->val = 4;
    temp1->next = new ListNode(0);

    ListNode *l3 = s1.addTwoNumbers(l1, l2);

    cout << "l1是:" << endl;
    cout << l1->val << "　" << (l1->next)->val << " " << (l1->next->next)->val << endl;

    cout << "l2是:" << endl;
    cout << l2->val << "　" << (l2->next)->val << " " << (l2->next->next)->val << endl;

    cout << "l3是:" << endl;
    cout << l3->val << "　" << (l3->next)->val << " " << (l3->next->next)->val << endl;
}
int main()
{

    test01();
    system("pause");
    return 0;
}
