#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
884. 两句话中的不常见单词
句子 是一串由空格分隔的单词。每个 单词 仅由小写字母组成。

如果某个单词在其中一个句子中恰好出现一次，在另一个句子中却 没有出现 ，那么这个单词就是 不常见的 。
给你两个 句子 s1 和 s2 ，返回所有 不常用单词 的列表。返回列表中单词可以按 任意顺序 组织。
*/

vector<string> uncommonFromSentences(string s1, string s2)
{
    unordered_map<string, int> m1;
    vector<string> result;
    string sTot = s1 + " " + s2;
    string temp;
    for (char c : sTot)
    {
        if (c != ' ')
            temp.append(1, c);
        else
        {
            m1[temp]++;
            temp.clear();
        }
    }

    for (auto it = m1.begin(); it != m1.end(); it++)
    {
        if (it->second == 1)
            result.push_back(it->first);
    }

    return result;
}
int main()
{
    string s1 = "apple apple banana peach";
    string s2 = "this is an appele";
    string stot = s1 + " " + s2;
    vector<string> ans = uncommonFromSentences(s1, s2);
    cout << stot << endl;
    for (auto c : ans)
    {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}