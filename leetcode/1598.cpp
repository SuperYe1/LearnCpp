#include "oftenUse.hpp"
#include <iostream>
#include <vector>
using namespace std;

int logSwInt(string s)
{
    if (s == "../")
        return 0;
    else if (s == "./")
        return 1;
    return 2;
}

int minOperations(vector<string> &logs)
{
    vector<vector<string>> dirs;
    int index = 0;
    for (auto &log : logs)
    {
        switch (logSwInt(log))
        {
        case 0:
            if (index > 0)
                index--;
            break;
        case 1:
            break;
        default:
            int depth = dirs.size();
            if(depth <= index)
                dirs.push_back(vector<string>());
            dirs[index++].push_back(log);
            break;
        }
    }
    return index;
}

int main()
{
    vector<string> logs = {"d1/","../","../","../"};
    cout<<minOperations(logs)<<endl;
    system("pause");
    return 0;
}