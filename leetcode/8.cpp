#include <iostream>
using namespace std;
#include <cmath>

int myAtoi(string str)
{
    // string str;
    // for (int i = 0; i < s.size(); i++)
    // {
    //     if (s[i] == ' ')
    //         continue;
    //     if (s[i] == '+' || s[i] == '-')
    //     {
    //         str = str + s[i];
    //         if (s[i + 1] > 47 && s[i + 1] < 58)
    //         {
    //             continue;
    //         }
    //         else
    //         {
    //             return 0;
    //         }
    //     }
    //     if (s[i] > 57 || s[i] < 48)
    //     {
    //         return 0;
    //     }

    //     if (s[i] > 47 && s[i] < 58)
    //     {
    //         str = str + s[i];
    //         if (s[i + 1] > 47 && s[i + 1] < 58)
    //         {
    //             continue;
    //         }
    //         else
    //         {
    //             break;
    //         }
    //     }
    // }

    // int res = 0;
    // if (str[0] == '-')
    // {
    //     for (int i = 1; i < str.size(); i++)
    //     {
    //         int temp = str[i] - '0';
    //         if (-res < INT_MIN / 10 || (-res == INT_MIN / 10 && temp > -(INT_MIN % 10)))
    //         {
    //             return INT_MIN;
    //         }
    //         res = res * 10 + temp;
    //     }
    // }
    // else if (str[0] == '+')
    // {
    //     for (int i = 1; i < str.size(); i++)
    //     {
    //         int temp = str[i] - '0';
    //         if (res > INT_MAX / 10 || (res == INT_MAX / 10 && temp > INT_MAX % 10))
    //         {
    //             return INT_MAX;
    //         }

    //         res = res * 10 + temp;
    //     }
    // }
    // else
    // {
    //     for (int i = 0; i < str.size(); i++)
    //     {
    //         int temp = str[i] - '0';
    //         if (res > INT_MAX / 10 || (res == INT_MAX / 10 && temp > INT_MAX % 10))
    //         {
    //             return INT_MAX;
    //         }

    //         res = res * 10 + temp;
    //     }
    // }
    // if (str[0] == '-')
    //     return -res;
    // else
    //     return res;

    unsigned long len = str.length();

    // 去除前导空格
    int index = 0;
    while (index < len)
    {
        if (str[index] != ' ')
        {
            break;
        }
        index++;
    }

    if (index == len)
    {
        return 0;
    }

    int sign = 1;
    // 处理第 1 个非空字符为正负符号，这两个判断需要写在一起
    if (str[index] == '+')
    {
        index++;
    }
    else if (str[index] == '-')
    {
        sign = -1;
        index++;
    }

    // 根据题目限制，只能使用 int 类型
    int res = 0;
    while (index < len)
    {
        char curChar = str[index];
        if (curChar < '0' || curChar > '9')
            break;


        if (res > INT_MAX / 10 || (res == INT_MAX / 10 && (curChar - '0') > INT_MAX % 10))
            return INT_MAX;
        if (res < INT_MIN / 10 || (res == INT_MIN / 10 && (curChar - '0') > -(INT_MIN % 10)))
            return INT_MIN;
        res = res * 10 + sign * (curChar - '0');
        index++;
    }
    return res;
}

int main()
{
    string s = "    -91283472332wwww";
    int str = myAtoi(s);
    cout << str << endl;

    system("pause");
    return 0;
}
