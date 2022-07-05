#include "oftenUse.hpp"
#include <iostream>
#include <vector>
using namespace std;

bool checkZeroOnes(string s)
{
    int n = s.size();
    if(n == 1)
        return s[0] == '1';
    int oneLen = 0, zeroLen = 0;
    int temp = 1;
    for (int i = 1; i < n;i++)
    {
        if(s[i] != s[i-1])
        {
            s[i] == '1' ? zeroLen = max(temp, zeroLen) : oneLen = max(temp, oneLen);
            temp = 1;
        }
        else
            temp++;
    }
    s[n-1] == '0' ? zeroLen = max(temp, zeroLen) : oneLen = max(temp, oneLen);
    return oneLen > zeroLen;
}

int main()
{
    string s = "111000";
    cout<<"The answer is "<<(checkZeroOnes(s)?"True":"False")<<endl;
    system("pause");
    return 0;
}