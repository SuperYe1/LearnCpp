#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    if(s.size()==0)
        return 0;
    unordered_map<char, int> window;
    int left = 0, right = 0, len = 1;
    while (right<s.size())
    {
        char c = s[right];
        right++;
        window[c]++;
        while(window[c]>1)
        {
            char d = s[left];
            left++;
            window[d]--;
        }
        len =max(len,right-left);
    }
    return len;
}

int main()
{
    cout<<"yechao\n"<<endl;
    system("pause");
    return 0;
}
