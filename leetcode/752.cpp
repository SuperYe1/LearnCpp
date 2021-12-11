#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

string upswitch(string combine, int j)
{
    string c = combine;
    if (c[j] == '9')
        c[j] = '0';
    else
        c[j] = c[j] + 1;
    return c;
}

string downswitch(string combine, int j)
{
    string c = combine;
    if (c[j] == '0')
        c[j] = '9';
    else
        c[j] = c[j] - 1;
    return c;
}

int openLock(vector<string> &deadends, string target)
{
    unordered_set<string> m;
    m.insert(deadends.begin(), deadends.end());
    if(m.count("0000")) return -1;
    int step = 0;
    queue<string> q;
    q.push("0000");
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            string combine = q.front();
            q.pop();
            if (combine == target)
                return step;
            for (int j = 0; j < 4; j++)
            {
                // string s = upswitch(combine, j);
                // if (!m.count(s))
                // {
                //     q.push(s);
                //     m.emplace(s);
                // }
                // s = downswitch(combine, j);
                // if (!m.count(s))
                // {
                //     q.push(s);
                //     m.emplace(s);
                // }
                for(int t = -1; t < 2; t += 2){
                        char y = (combine[j] -'0' + 10 + t) % 10 + '0';
                        string x = combine;
                        x[j] = y;
                        if(!m.count(x)){
                            q.push(x);
                            m.emplace(x);
                        }
                    }
            }
        }
        step++;
    }
    return -1;
}

int main()
{

    system("pause");
    return 0;
}
