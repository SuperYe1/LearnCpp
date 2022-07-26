#include "oftenUse.hpp"
#include <iostream>
#include <random>
#include <vector>
using namespace std;

const double CHANCE = 0.25;
const int MAXLEVEL = 32;
struct SkiplistNode
{
    int val;
    vector<SkiplistNode *> next;
    SkiplistNode(int val) : val(val), next(MAXLEVEL, NULL) {}
};
class Skiplist
{
private:
    SkiplistNode *head;
    int level;

public:
    Skiplist() : head(new SkiplistNode(-1)), level(10) {}
    ~Skiplist()
    {
        delete head;
    }
    void find(int target, vector<SkiplistNode *> &nodes)
    {
        auto cur = head;
        for (int i = level - 1; i >= 0; i--)
        {
            while (cur->next[i] && cur->next[i]->val < target)
                cur = cur->next[i];
            nodes[i] = cur;
        }
    }
    bool search(int target)
    {
        vector<SkiplistNode *> pre(level);
        find(target, pre);
        auto p = pre[0]->next[0];
        return p && p->val == target;
    }

    void add(int num)
    {
        vector<SkiplistNode *> update(level);
        find(num, update);
        auto p = new SkiplistNode(num);
        for (int i = 0; i < level; i++)
        {
            p->next[i] = update[i]->next[i];
            update[i]->next[i] = p;
            if (rand() % 2 == 0)
                break;
        }
    }

    bool erase(int num)
    {
        vector<SkiplistNode *> pre(level);
        find(num, pre);
        auto p = pre[0]->next[0];
        if (!p || p->val != num)
            return false;
        for (int i = 0; i < level && pre[i]->next[i] == p; i++)
            pre[i]->next[i] = p->next[i];
        delete p;
        return true;
    }
};

int main()
{
    mt19937 gen{random_device{}()};
    uniform_real_distribution<double> dis(0, 1);
    cout << gen << endl;

    system("pause");
    return 0;
}