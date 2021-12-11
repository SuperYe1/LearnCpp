#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool checkInclusion(string s1, string s2)
{
    if (s1.size() == 0 || s2.size() == 0 || s1.size() > s2.size())
        return false;
    unordered_map<char, int> need, window;
    for (char c : s1)
        need[c]++;
    int left = 0, right = 0, vaild = 0;
    while (right < s2.size())
    {
        char c = s2[right];
        right++;
        if (need.count(c))
        {
            window[c]++;
            if (window[c] == need[c])
                vaild++;
        }
        while (right - left >= s1.size())
        {
            if (vaild == need.size())
                return true;
            char d = s2[left];
            left++;
            if(need.count(d))
            {
                if(window[d] == need[d])
                    vaild--;
                window[d]--;
            }
        }
    }
    return false;
}

int main()
{
    string s1 = "ab",s2 = "acb";
    cout << checkInclusion(s1, s2) << endl;

    system("pause");
    return 0;
}
