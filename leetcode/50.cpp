#include <iostream>
using namespace std;

double quickPow(double x, long long n)
{
    double x1 = x;
    double ans = 1.0;
    while (n > 0)
    {
        if (n % 2 == 1)
            ans = ans * x1;
        x1 *= x1;
        n /= 2;
    }
    return ans;
}
double myPow(double x, int n)
{
    long long N = n;
    if (n == 0)
        return 1.0;
        return n>0? quickPow(x,N):(1.0/quickPow(x,-N));
}

int main()
{
    double b = 2.0000;
    int n = 10;
    cout << myPow(b, n) << endl;
    double x = 1.000, y = 1.0;
    bool a = (x == y);
    cout << a << endl;
    system("pause");
    return 0;
}
