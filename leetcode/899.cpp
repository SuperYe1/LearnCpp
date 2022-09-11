#include "oftenUse.hpp"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

string orderlyQueue(string s, int k)
{
    if (k > 1)
    {
        sort(s.begin(), s.end());
        return s;
    }
    else
    {
        string ans = s;
        int n = s.size();
        int i = 0, j = 1, k = 0;
        while (i < n && k < n && j < n)
        {
            if (s[(i + k) % n] == s[(j + k) % n])
                k++;
            else
            {
                s[(i + k) % n] > s[(j + k) % n] ? i = i + k + 1 : j = j + k + 1;
                k = 0;
                if(i==j)
                    i++;
            }
        }
        i = min(i, j);
        return s.substr(i,n-i)+s.substr(0,i);
    }
}
int main()
{
    string s = "cba";
    cout << orderlyQueue(s, 1) << endl;
    system("pause");
    return 0;
}