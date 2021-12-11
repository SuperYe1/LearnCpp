#include <iostream>
#include <vector>
using namespace std;
#include <cmath>
int climbStairs(int n)
{
    int a1 = 1, a2 = 2, res;
    if (n == 1)
        return a1;
    if (n == 2)
        return a2;
    for (int i = 3;i<=n;i++)
    {
        res = a1 + a2;
        a1 = a2;
        a2 = res;
    }
    return res;
}
int main()
{
    int n = 6;
    int res = 1;
    int num2 = n / 2;
    // if (num2 == 0)
    //     return 1;
    for (int i = 1; i <= num2; i++)
    {
        int temp = n - 2 * i + i;
        int cti = 1;
        for (int j = 1; j <= i; j++)
            cti = cti * (temp - j + 1) / j;
        res += cti;
        cout << res << endl;
    }
    cout << res;

    system("pause");
    return 0;
}
