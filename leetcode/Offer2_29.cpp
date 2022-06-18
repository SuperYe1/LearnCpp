#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node() {}

    Node(int _val)
    {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node *_next)
    {
        val = _val;
        next = _next;
    }
};

Node *insert(Node *head, int insertVal)
{
    Node *insertNode = new Node(insertVal);
    insertNode->next = insertNode;
    if(head == NULL)
        return insertNode;
    if(head->next == head)
    {
        head->next = insertNode;
        insertNode->next = head;
        return head;
    }
    Node *prev = head;
    while(prev->next!=head)
    {
        if(prev->val <= insertVal && prev->next->val >= insertVal)
            break;
        if(prev->val >prev->next->val)
        {
            if(insertVal<prev->next->val ||insertVal>prev->val)
                break;
        }
        prev = prev->next;
    }
    insertNode->next = prev->next;
    prev->next = insertNode;
    return head;
}

int main()
{

    system("pause");
    return 0;
}