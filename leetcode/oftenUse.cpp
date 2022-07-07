#include "oftenUse.hpp"
using namespace std;

PrefixTree::PrefixTree()
{
    root = new TriNode();
}
PrefixTree::~PrefixTree(){};
void PrefixTree::add(string str)
{
    TriNode *temp = root;
    if (str.empty())
        return;
    temp->pass++;
    for (int i = 0; i < str.size(); i++)
    {
        int index = str[i] - 'a';
        if (temp->next[index] == nullptr)
            temp->next[index] = new TriNode();
        temp = temp->next[index];
        temp->pass++;
    }
    temp->isEnd = true;
}

bool PrefixTree ::findStr(string str)
{
    if (str.empty())
        return false;
    TriNode *temp = root;
    for (int i = 0; i < str.size(); i++)
    {
        int index = str[i] - 'a';
        if (temp->next[index] == nullptr)
            return false;
        temp = temp->next[index];
    }
    return temp->isEnd;
}

int PrefixTree::findPrefix(string str)
{
    if (str.empty())
        return false;
    TriNode *temp = root;
    for (int i = 0; i < str.size(); i++)
    {
        int index = str[i] - 'a';
        if (temp->next[index] == nullptr)
            return false;
        temp = temp->next[index];
    }
    return temp->pass;
}

void PrefixTree::erase(string str)
{
    if (str.empty() || !findStr(str))
        return;
    TriNode *temp = root;
    temp->pass--;
    for (int i = 0; i < str.size(); i++)
    {
        int index = str[i] - 'a';
        if (--temp->next[index]->pass == 0)
        {
            TriNode *cur = temp->next[index];
            stack<TriNode *> stk;
            stk.push(cur);
            while (!stk.empty())
            {
                TriNode *now = stk.top();
                stk.pop();
                for (int i = 0; i < 26; i++)
                {
                    if (now->next[i] != NULL)
                        stk.push(now->next[i]);
                }
                delete now;
            }
        }
        temp = temp->next[index];
    }
    temp->isEnd = false;
}