#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
#include <stack>

string reverseParentheses(string s)
{
    // stack<string> stk;
    // string str;
    // for (char ch : s)
    // {
    //     if (ch == '(')
    //     {
    //         stk.push(str);
    //         str = "";
    //     }
    //     else if (ch == ')')
    //     {
    //         reverse(str.begin(), str.end());
    //         str = stk.top() + str;
    //         stk.pop();
    //     }
    //     else
    //     {
    //         str.push_back(ch);
    //     }
    // }
    // return str;

    int n = s.length();
    vector<int> pair(n);
    stack<int> stk;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            stk.push(i);
        }
        else if (s[i] == ')')
        {
            int j = stk.top();
            stk.pop();
            pair[i] = j;
            pair[j] = i;
        }
    }

    int index = 0, step = 1;
    string ans;
    while (index < n)
    {
        if (s[index] == '(' || s[index] == ')')
        {
            index = pair[index];
            step = -step;
        }
        else
        {
            ans.push_back(s[index]);
        }
        index += step;
    }
    return ans;
}

int main()
{

    system("pause");
    return 0;
}
