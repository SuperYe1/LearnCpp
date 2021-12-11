#include <iostream>
using namespace std;
#include <vector>

string longestCommonPrefix(vector<string> &strs)
{
    if (!strs.size())
        return "";
    int maxNum = strs[0].size();

    for (int j = 0; j < maxNum; j++)
    {
        char c = strs[0][j];
        for (int i = 0; i < strs.size() ; i++)
        {
            if (j == strs[i].size() || strs[i][j]!=c)

                return strs[0].substr(0, j);
        }

    }
    return strs[0];
}
int main()
{

    system("pause");
    return 0;
}
