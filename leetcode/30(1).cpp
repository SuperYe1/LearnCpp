#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> findSubstring(string s, vector<string> &words)
{
    unordered_map<string, int> m;
    vector<int> res;
    if (words.size() == 0)
        return res;
    int totalnum = 0, singerNum = words[0].size();
    for (auto word : words)
    {
        m[word]++;
        totalnum += word.size();
    }
    for (int i = 0; i < s.size() - totalnum + 1; i++)
    {
        int j = 0;
        unordered_map<string, int> m1;
        for (j = i; j < i + totalnum; j = j+singerNum)
        {
            string str = s.substr(j, singerNum);
            if (m[str] == 0)
                break;
            else
            {
                m1[str]++;
                if (m[str] < m1[str])
                    break;
            }
        }
        if (j == i+totalnum)
            res.push_back(i);
    }
    return res;
}

int main()
{

    system("pause");
    return 0;
}