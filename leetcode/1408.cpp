#include "oftenUse.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<string> stringMatching(vector<string> &words)
{
    auto str = accumulate(words.cbegin(), words.cend(), string(), [](auto &&a, auto &&b)
                          { return a + ',' + b; });
    vector<string> ans;
    copy_if(words.cbegin(), words.cend(), back_inserter(ans), [&str](auto &&s)
            { return str.find(s, str.find(s) + 1) != string::npos; });
    return ans;
}
int main()
{

    system("pause");
    return 0;
}