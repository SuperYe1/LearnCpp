#include "oftenUse.hpp"
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
{
    stack<int> qu;
    int index = 0;
    for (int i = 0;i<pushed.size() && index <pushed.size();i++)
    {
        qu.push(pushed[i]);
        while(!qu.empty() && qu.top() == popped[index])
        {
            qu.pop();
            index++;
        }
    }
    return qu.empty();
}

int main()
{

    system("pause");
    return 0;
}