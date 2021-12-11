#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>

vector<int> findSubstring(string s, vector<string> &words)
{
    unordered_map<string, int> m;
    vector<int> res;
    if (words.size() == 0)
        return res;
    int totalNum;
    int singleNum = words[0].size();
    for (int i = 0; i < words.size(); i++)
    {
        totalNum += words[i].size();
        m[words[i]]++;
    }
    for (int i = 0; i < s.size() - totalNum + 1; i++)
    {
        unordered_map<string, int> m1;
        int j = 0;
        for (j = i; j < i + totalNum; j = j + singleNum)
        {
            string tempStr = s.substr(j, singleNum);
            if (m[tempStr] == 0)
                break;
            else
            {
                m1[tempStr]++;
                if (m[tempStr] < m1[tempStr])
                    break;
            }
        }
        if (j == i + totalNum)
            res.push_back(i);
    }
    return res;
}
int main()
{
    vector<string> words = {"word", "good", "best", "word"};
    unordered_map<string, int> m;
    int totalNum;
    for (int i = 0; i < words.size(); i++)
    {
        totalNum += words[i].size();
        m[words[i]]++;
    }

    for (unordered_map<string, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    cout << totalNum << endl;

    system("pause");
    return 0;
}
