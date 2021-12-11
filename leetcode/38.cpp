#include <iostream>
using namespace std;
#include <vector>

void muFunc(vector<string> &res, int n)
{
    string s2, s1 = res[n - 1];
    vector<int> temp;
    for (char c : s1)
    {
        int i = c - '0';
        temp.push_back(i);
    }
    int num = 1;
    for (int i = 1; i < temp.size(); i++)
    {
        if (temp[i] == temp[i - 1])
        {
            num++;
        }
        else
        {
            s2.push_back(num + '0');
            s2.push_back(temp[i - 1] + '0');
            num = 1;
        }
    }
    s2.push_back(num + '0');
    s2.push_back(temp.back() + '0');
    res.push_back(s2);
}
string countAndSay(int n)
{
    vector<string> res;
    res.push_back("1");
    for (int i = 1; i <= n; i++)
    {
        muFunc(res, i);
    }
    return res[n - 1];
}
int main()
{


    system("pause");
    return 0;
}
