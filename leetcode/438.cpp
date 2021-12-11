#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> findAnagrams(string s, string p)
{
    if (s.size() < p.size() || s.size() == 0 || p.size() == 0)
        return {};
    vector<int> res;
    // vector<int> need(26), window(26);
    // for (int i = 0; i < p.size(); ++i)
    // {
    //     need[p[i] - 'a']++;
    //     window[s[i] - 'a']++;
    // }
    // if(need==window)
    //     res.push_back(0);
    // for (int i = p.size(); i < s.size();i++)
    // {
    //     window[s[i] - 'a']++;
    //     window[s[i-p.size()] - 'a']--;
    //     if(need==window)
    //         res.push_back(i - p.size()+1);
    // }
    // return res;

    unordered_map<char, int> need, window;
    for (char c : p)
        need[c]++;
    int left = 0,
        right = 0,
        vaild = 0;
    while (right < s.size())
    {
        char c = s[right];
        right++;
        if(need.count(c))
        {
            window[c]++;
            if(need[c]==window[c])
                vaild++;
        }
        while(right-left>=p.size())
        {
            if(vaild == need.size())
                res.push_back(left);
            char d = s[left];
            left++;
            if(need.count(d))
            {
                if(need[d]==window[d])
                    vaild--;
                window[d]--;
            }
        }
    }
    return res;
}

int main()
{

    system("pause");
    return 0;
}
