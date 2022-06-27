#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool isSubsequence(string s, string t)
{
    int n = s.length(), m = t.length();
    if (n > m)
        return false;
    int sindex = 0, tindex = 0;
    while (sindex < n && tindex < m)
    {
        if (s[sindex] == t[tindex])
            sindex++;
        tindex++;
    }
    return sindex == n;
}

int findLUSlength(vector<string> &strs)
{
    int n = strs.size();
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        bool check = true;
        for (int j = 0; j < n; j++)
        {
            if(i!=j&&isSubsequence(strs[i],strs[j]))
            {
                check = false;
                break;
            }
        }
        if(check)
        ans = max(ans,(int)strs[i].size());
    }
    return ans;
}

int main()
{
    string s = "abc";
    string t = "ahkblwwwcs";
    cout << (isSubsequence(s, t) ? "ture" : "false") << endl;
    system("pause");
    return 0;
}