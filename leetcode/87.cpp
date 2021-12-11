#include <iostream>
#include <vector>
using namespace std;

bool isScramble(string s1, string s2)
{

    //暴力
    // if (s1.size() != s2.size())
    //     return false;
    // if (s1 == s2)
    //     return true;
    // int n = s1.size();
    // int zimu[26] = {0};
    // for (int i = 0; i < n; i++)
    // {
    //     zimu[s1[i] - 'a']++;
    //     zimu[s2[i] - 'a']--;
    // }
    // for (int i = 0; i < 26; i++)
    // {
    //     if (zimu[i] != 0)
    //         return false;
    // }
    // for (int i = 1; i < n; i++)
    // {
    //     if ((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) || (isScramble(s1.substr(i), s2.substr(0, n - i)) && isScramble(s1.substr(0, i), s2.substr(n - i))) |)
    //     {
    //         return true;
    //     }
    // }
    // return false;

    //动态规划

}

int main()
{

    system("pause");
    return 0;
}
