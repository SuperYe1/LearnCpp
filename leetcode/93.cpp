#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int SEG_COUNT = 4;
vector<string> ans;
vector<int> seg;

void dfs(string s, int segId, int segStart)
{
    if (segId == SEG_COUNT)
    {
        if (segStart == s.size())
        {
            string ipAddr;
            for (int i = 0; i < SEG_COUNT; i++)
            {
                ipAddr += to_string(seg[i]);
                if (i != SEG_COUNT - 1)
                    ipAddr += ".";
            }
            ans.push_back(ipAddr);
        }
        return;
    }

    if (segStart == s.size())
        return;
    if (s[segStart] == '0')
    {
        seg[segId] = 0;
        dfs(s, segId + 1, segStart + 1);
    }

    int addr = 0;
    for (int i = segStart; i < s.size(); i++)
    {
        addr = addr * 10 + (s[i] - '0');
        if (addr > 0 && addr <= 255)
        {
            seg[segId] = addr;
            dfs(s, segId + 1, i + 1);
        }
        else
            break;
    }
}
vector<string> restoreIpAddresses(string s)
{
    seg.resize(SEG_COUNT);
    dfs(s, 0, 0);
    return ans;
}

int main()
{

    system("pause");
    return 0;
}
