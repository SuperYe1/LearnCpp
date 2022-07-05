#include "oftenUse.hpp"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(long x)
{
    if (x < 0 || (x % 10 == 0 && x != 0))
    {
        return false;
    }

    long revertedNumber = 0;
    while (x > revertedNumber)
    {
        revertedNumber = revertedNumber * 10 + x % 10;
        x /= 10;
    }
    return x == revertedNumber || x == revertedNumber / 10;
}

int superpalindromesInRange(string left, string right)
{
    int res = 0;
    long l = stol(left);
    long r = stol(right);

    // 先判断偶数的情况 ABCCBA
    for (int i = 1; i < 100000; ++i)
    {
        string s = to_string(i);
        string s2 = s;
        reverse(s2.begin(), s2.end());
        long m = stol(s + s2);
        m *= m;
        // 超过范围提前结束遍历
        if (m > r)
        {
            break;
        }
        else if (m >= l && isPalindrome(m))
        {
            ++res;
        }
    }

    // 再判断奇数的情况 ABCBA
    for (int i = 1; i < 100000; ++i)
    {
        string s = to_string(i);
        string s2 = s;
        reverse(s2.begin(), s2.end());
        long m = stol(s.append(s2.begin() + 1, s2.end()));
        m *= m;
        // 超过范围提前结束遍历
        if (m > r)
        {
            break;
        }
        else if (m >= l && isPalindrome(m))
        {
            ++res;
        }
    }

    return res;
}

// int superpalindromesInRange(string left, string right)
// {
//     long L = stol(left);
//     long R = stol(right);
//     int MAGIC = 100000;
//     int ans = 0;
//     for (int k = 1; k < MAGIC; k++)
//     {
//         string s = to_string(k);
//         string s2 = s;
//         reverse(s2.begin(), s2.end());
//         long v = stol(s + s2);
//         v *= v;
//         if (v > R)
//             break;
//         if (v >= L && isPalindrome(v))
//             ans++;
//     }
//     for (int k = 1; k < MAGIC; k++)
//     {
//         string s = to_string(k);
//         string s2 = s;
//         reverse(s2.begin(), s2.end());
//         long v = stol(s.append(s2.begin()+1, s2.end()));
//         v *= v;
//         if (v > R)
//             break;
//         if (v >= L && isPalindrome(v))
//             ans++;
//     }
//     return ans;
// }
int main()
{

    system("pause");
    return 0;
}