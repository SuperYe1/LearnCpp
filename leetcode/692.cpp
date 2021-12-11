#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<string> topKFrequent(vector<string> &words, int k)
{
    vector<string> rec;
    unordered_map<string, int> cnt;
    for (string word : words)
    {
        cnt[word]++;
    }

    //排序
    // for (auto &[key, value] : cnt)
    // {
    //     rec.push_back(key);
    // }
    // sort(rec.begin(), rec.end(), [&](const string &a, const string &b) -> bool {
    //     return cnt[a] == cnt[b] ? a < b : cnt[a] > cnt[b];
    // });
    // rec.erase(rec.begin()+k, rec.end());
    // return rec;

    //优先队列


}

int main()
{

    system("pause");
    return 0;
}
