#include <iostream>
#include <vector>
using namespace std;

/*
最后一个单词的长度

给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中最后一个单词的长度。
单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。
*/

int lengthOfLastWord(string s)
{
    int n = s.size();
    int cnt;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != ' ')
            if (i == 0 || s[i - 1] == ' ')
                cnt = 1;
            else
                cnt++;
    }
    return cnt;
}
int main()
{
    string s = "luffy is still joyboy";
    cout << "the last word's number of s is "<< lengthOfLastWord(s) << endl;
    return 0;
}