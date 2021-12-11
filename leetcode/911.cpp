#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
911. 在线选举
给你两个整数数组 persons 和 times 。
在选举中，第 i 张票是在时刻为 times[i] 时投给候选人 persons[i] 的。
对于发生在时刻 t 的每个查询，需要找出在 t 时刻在选举中领先的候选人的编号。
在 t 时刻投出的选票也将被计入我们的查询之中。
在平局的情况下，最近获得投票的候选人将会获胜。
*/

class TopVotedCandidate
{
private:
    vector<int> tops;
    vector<int> times;

public:
    TopVotedCandidate(vector<int> &persons, vector<int> &times)
    {
        unordered_map<int, int> m;
        int top = -1;
        m[top] = -1;
        for (int i = 0; i < times.size(); i++)
        {
            m[persons[i]]++;
            if (m[persons[i]] >= m[top])
                top = persons[i];
            tops.push_back(top);
        }
        this->times = times;
        for (int i = 0; i < times.size(); i++)
            cout << tops[i] << " ";
        cout << endl;
    }

    int q(int t)
    {
        int left = 0, right = times.size() - 1, ans;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (times[mid] > t)
                right = mid - 1;
            else
            {
                ans = mid;
                left = mid + 1;
            }
        }
        cout << left << endl;
        return tops[ans];
    }
};

int main()
{
    vector<int> persons = {0, 1, 1, 0, 0, 1, 0};
    vector<int> times = {0, 5, 10, 15, 20, 25, 30};
    TopVotedCandidate *t = new TopVotedCandidate(persons, times);
    cout << t->q(3) << endl;

    return 0;
}