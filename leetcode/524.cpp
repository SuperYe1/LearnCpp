#include <iostream>
#include <vector>
using namespace std;

/*
通过删除字母匹配到字典里最长单词
给你一个字符串 s 和一个字符串数组 dictionary 作为字典，
找出并返回字典中最长的字符串，该字符串可以通过删除 s 中的某些字符得到。
*/

//暴力解法,双指针
bool checkStr(string s, string str)
{
    int tem = 0, len = str.size();
    int cur = 0;
    for (; cur < s.size(); cur++)
    {
        if(tem>=len)
            break;
        if (s[cur] == str[tem])
            tem++;
    }
    if (tem == len)
        return true;
    else
        return false;
}


string findLongestWord(string s, vector<string> &dictionary)
{
    int curSize = 0;
    string ans = "";
    for (auto &str : dictionary)
    {
        if (str.size() < curSize)
            continue;
        if (checkStr(s, str))
        {
            if (str.size() > curSize || str.compare(ans)<0)
            {
                curSize = str.size();
                ans = str;
            }
        }
    }
    return ans;
}

//动态规划








int main()
{
    vector<string> dictionary;
    dictionary.push_back("c");
    dictionary.push_back("a");
    dictionary.push_back("b");
    string s = "abpcplea";
    cout << findLongestWord(s, dictionary) << endl;

    return 0;
}