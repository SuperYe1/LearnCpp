#include "oftenUse.hpp"
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> fracType;

int gcd(int x, int y)
{
    while (y != 0)
    {
        int temp = x % y;
        x = y;
        y = temp;
    }
    return x;
}

fracType calcuFrac(fracType a, fracType b)
{
    fracType res;
    res.first = a.first * b.second + b.first * a.second;
    if (res.first == 0)
    {
        res.second = 1;
        return res;
    }
    res.second = a.second * b.second;
    return res;
}

bool isNum(char a)
{
    return (a >= '0' && a <= '9');
}
fracType getFrac(string expression, int &i)
{
    fracType res(100, 100);
    int len = expression.length();
    int lowZero = 1;
    int temp = 100;

    while (i <= len)
    {
        if (i == len || !isNum(expression[i]))
        {
            if (temp != 100)
            {
                if (res.first == 100)
                {
                    res.first = lowZero * temp;
                    lowZero = 1;
                }
                else
                {
                    res.second = lowZero * temp;
                    break;
                }
            }
            if (expression[i] == '-')
                lowZero = -1;
            temp = 0;
        }
        else
        {
            temp = temp * 10 + expression[i] - '0';
        }
        i++;
    }
    return res;
}
string fractionAddition(string expression)
{
    int len = expression.length();
    if (len <= 4)
        return expression;
    fracType a(10, 10), b(10, 10);
    int i = 0;
    if (isNum(expression[i]))
    {
        expression = "+" + expression;
    }
    a = getFrac(expression, i);

    while (i < len)
    {
        b = getFrac(expression, i);
        a = calcuFrac(a, b);
    }
    if (a.first == 0)
        return "0/1";
    int g = gcd(abs(a.first), a.second);
    return to_string(a.first / g) + "/" + to_string(a.second / g);
}

int main()
{
    fracType a;
    string str = "-5/2+10/3+7/9";
    int i = 0;
    a = getFrac(str, i);
    cout << to_string(a.first) + "/" + to_string(a.second) << " " << i << endl;
    cout << fractionAddition(str) << endl;
    system("pause");
    return 0;
}