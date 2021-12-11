#include <iostream>
#include <vector>
using namespace std;

/*
两整数之和
给你两个整数 a 和 b ，不使用 运算符 + 和 - ​​​​​​​，计算并返回两整数之和。
*/

int getSum(int a, int b)
{
    while (b != 0)
    {
        unsigned int carry = (unsigned int)(a & b) << 1;
        a = a ^ b;
        b = carry;
    }
    return a;
}

int main()
{

    return 0;
}