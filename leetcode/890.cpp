#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*


*/
vector<string> findAndReplacePattern(vector<string> &words, string pattern)
{
    vector<string> ans;
    int n = pattern.size();
    for (int j = 0; j < words.size(); j++)
    {
        string word = words[j];
        unordered_map<char, char> mp;
        unordered_map<char, bool> isused;
        bool isfalse = true;
        for (int i = 0; i < n; i++)
        {
            if (!mp.count(word[i]))
            {
                if (isused.count(pattern[i]))
                {
                    isfalse = false;
                    break;
                }
                mp[word[i]] = pattern[i];
                isused[pattern[i]] = true;
            }
            word[i] = mp[word[i]];
        }
        if (isfalse && word == pattern)
            ans.push_back(words[j]);
    }
    return ans;
}
int main()
{

    return 0;
}