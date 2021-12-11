#include <iostream>
using namespace std;
#include <stack>
#include <vector>

int longestValidParentheses(string s)
{
    // stack<int> s1;
    // vector<int> num;
    // int temp(0);
    // int res = 0;
    // for (int i = 0; i < s.size(); i++)
    // {
    //     if (s[i] == '(')
    //     {
    //         s1.push(i);
    //     }
    //     else
    //     {
    //         if (s1.size() == 0)
    //         {
    //             num.push_back(res + temp);
    //             temp = 0;
    //             res = 0;
    //             continue;
    //         }
    //         s1.pop();
    //         if (s1.size() == 0)
    //         {
    //             res = res + temp + 2;
    //             temp = 0;
    //             num.push_back(res);
    //         }
    //         else
    //         {
    //             temp = i - s1.top();
    //             num.push_back(temp);
    //         }
    //     }
    // }
    // int result = 0;
    // for (int i = 0; i < num.size(); i++)
    // {
    //     result = result < num[i] ? num[i] : result;
    // }
    // return result;

    int maxans = 0;
    stack<int> stk;
    stk.push(-1);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            stk.push(i);
        }
        else
        {
            stk.pop();
            if (stk.empty())
            {
                stk.push(i);
            }
            else
            {
                maxans = max(maxans, i - stk.top());
            }
        }
    }
    return maxans;
}

int main()
{
    string s = "()()())";
    int result = longestValidParentheses(s);

    cout << "result" << endl
         << result << endl;

    system("pause");
    return 0;
}
