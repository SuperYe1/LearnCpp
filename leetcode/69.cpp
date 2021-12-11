#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int mySqrt(int x)
{
    //二分查找
    // if (x == 0)
    //     return 0;
    // int left = 1, right = x, ans = 0;
    // while (left <= right)
    // {
    //     int mid = left + (right - left) / 2;
    //     if ((long long)mid * mid <= x)
    //     {
    //         ans = mid;
    //         left = mid + 1;
    //     }
    //     else
    //         right = mid - 1;
    // }
    // return ans;

    //牛顿迭代
    if (x == 0)
        return 0;
    double c = x, x0 = x;
    while (true)
    {
        double xi = 0.5 * (x0 + c / x0);
        if (fabs(xi - x0) < 1e-7)
            break;
        x0 = xi;
    }
    return int(x0);
}
int main()
{
    int x = INT_MAX;
    cout << mySqrt(x) << endl;

    system("pause");
    return 0;
}
