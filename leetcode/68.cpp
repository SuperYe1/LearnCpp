#include <iostream>
#include <vector>
using namespace std;

string fillwords(vector<string> &words, int begin, int end, int maxWidth, bool lastLine)
{
    int num = end - begin + 1;
    int spaceCount = maxWidth + 1 - num;
    for (int i = begin; i <= end; ++i)
        spaceCount -= words[i].size();
    int wordSpace = 1;
    int spaceAvg = (num == 1) ? 1 : spaceCount / (num - 1);
    int spaceExt = (num == 1) ? 0 : spaceCount % (num - 1);
    string combine;
    for (int i = begin; i < end; ++i)
    {
        combine += words[i];
        if (lastLine)
        {
            combine += string(1, ' ');
            continue;
        }
        combine += string(spaceAvg + wordSpace + ((i - begin) < spaceExt), ' ');
    }

    combine += words[end];
    int n = combine.size();
    combine += string(maxWidth - n, ' ');
    return combine;
}
vector<string> fullJustify(vector<string> &words, int maxWidth)
{
    vector<string> res;
    int n = words.size();
    int total = 0;
    int begin = 0;
    for (int i = 0; i < n; ++i)
    {
        total += words[i].size() + 1;
        if (i == n - 1 || total + words[i + 1].size() > maxWidth)
        {
            res.push_back(fillwords(words, begin, i, maxWidth, (i + 1 == n)));
            begin = i + 1;
            total = 0;
        }
    }
    return res;
}

int main()
{
    string s = "word";
    int n = 5;
    string s1 = s + string(n, ' ');
    cout << s1;

    system("pause");
    return 0;
}
