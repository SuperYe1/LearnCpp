#include <iostream>
using namespace std;
#include <cmath>

long div1(long a, long b)
{
    if (a < b)
        return 0;
    long count = 1;
    long tb = b;
    while ((tb + tb < a))
    {
        count = count + count;
        tb = tb + tb;
    }
    return count + div1(a - tb, b);
}
int divide(int dividend, int divisor)
{
    if (dividend == 0)
        return 0;
    if (divisor == 1)
        return dividend;
    if (divisor == -1)
    {
        if (dividend > INT_MIN)
            return -dividend; // 只要不是最小的那个整数，都是直接返回相反数就好啦
        return INT_MAX;       // 是最小的那个，那就返回最大的整数啦
    }
    int index =1;
    if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
    {
        index = -1;
    }
    long bit;
    long a = (dividend < 0 ? -dividend : dividend);
    long b = (divisor < 0 ? -divisor : divisor);
    bit = div1(a, b);
    if (index > 1)
        return bit > INT_MAX ? INT_MAX : bit;
    return index * bit;
}

int main()
{
    int a = 122;
    int b = -1;
    cout << divide(a, b) << endl;
    cout << INT_MIN << endl;

    system("pause");
    return 0;
}
