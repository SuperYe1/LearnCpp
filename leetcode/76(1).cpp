#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

string minWindow(string s, string t)
{
    if (s.size() == 0 || t.size() == 0 || s.size() < t.size())
        return "";
    unordered_map<char, int> need, window;
    int left = 0, right = 0, vaild = 0, len = INT_MAX, start = 0;
    for (char c : t)
        need[c]++;
    while (right < s.size())
    {
        char c = s[right];
        right++;
        if (need.count(c))
        {
            window[c]++;
            if (window[c] == need[c])
                vaild++;
        }
        while (vaild == need.size())
        {
            if(right-left<len)
            {
                start = left;
                len = right-left;
            }
            char d = s[left];
            left++;
            if (need.count(d))
            {
                if (window[d] == need[d])
                    vaild--;
                window[d]--;
            }
        }
    }
    return (len == INT_MAX) ? "" : s.substr(start, len);
}
int main()
{

    system("pause");
    return 0;
}
