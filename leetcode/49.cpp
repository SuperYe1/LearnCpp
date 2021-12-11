#include <iostream>
using namespace std;
#include <algorithm>
#include <unordered_map>
#include <vector>

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> res;
    unordered_map<string, vector<int>> m;
    int n = strs.size();
    for (int i = 0; i < n; ++i)
    {
        string temp = strs[i];
        sort(temp.begin(), temp.end());
        m[temp].push_back(i);
    }
    for (unordered_map<string, vector<int>> :: iterator it = m.begin(); it != m.end(); ++it)
    {
        vector<string> temp;
        for(int i = 0; i < it->second.size(); ++i)
        {
            temp.push_back(strs[it->second[i]]);
        }
        res.push_back(temp);
    }
    return res;
}

int main()
{
    string str = "abekfiakge";
    sort(str.begin(), str.end());
    cout << str << endl;

    system("pause");
    return 0;
}
