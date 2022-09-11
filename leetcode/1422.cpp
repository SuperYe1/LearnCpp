#include "oftenUse.hpp"
#include <iostream>
#include <vector>
using namespace std;

int maxScore(string s)
{
    int res = 0;
    int num1 = 0, num0 = 0;
    int now1 = 0, now0 = 0;
    for(char c:s)
    {
        if (c=='1')
            num1++;
        else
            num0++;
    }
    for (int i = 0; i < s.size() - 1;i++)
    {
        char c = s[i];
        if(c == '1')
            now1++;
        else
            now0++;
        res = max(res, now0 + num1 - now1);
    }
    return res;
}

int main()
{

    system("pause");
    return 0;
}