#include <iostream>
#include <vector>
using namespace std;

/*
537. 复数乘法
复数 可以用字符串表示，遵循 "实部+虚部i" 的形式，并满足下述条件：

实部 是一个整数，取值范围是 [-100, 100]
虚部 也是一个整数，取值范围是 [-100, 100]
i2 == -1
给你两个字符串表示的复数 num1 和 num2 ，
请你遵循复数表示形式，返回表示它们乘积的字符串。
*/

void complexToint(string num1, int *a, int *b)
{
    int postSym = 0;
    for (int i = num1.size() - 1; i >= 0; i--)
    {
        if (num1[i] == '+' || num1[i] == '-')
        {
            postSym = i;
            break;
        }
    }
    string temp1 = num1.substr(0, postSym);
    *a = atoi(temp1.c_str());
    temp1 = num1.substr(postSym, num1.size() - 1 - postSym);
    *b = atoi(temp1.c_str()); 
}

string complexNumberMultiply(string num1, string num2)
{
    int numa, numb, numc, numd;
    int numx, numy;
    string result;

    complexToint(num1, &numa, &numb);
    complexToint(num2, &numc, &numd);
    numx = numa * numc - numb * numd;
    numy = numa * numd + numc * numb;
    result = to_string(numx) + "+" + to_string(numy) + "i";

    return result;
}

int main()
{
    string num1 = "1-1i";
    string num2 = "1-1i";
    int a, b;
    complexToint(num1, &a, &b);
    cout << "a = " << a << "  b = " << b << endl;
    complexToint(num2, &a, &b);
    cout << "a = " << a << "  b = " << b << endl;
    cout << complexNumberMultiply(num1, num2) << endl;
    return 0;
}