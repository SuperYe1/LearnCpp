#include <iostream>
using namespace std;

int reverse(int x)
{
    int res = 0;
    if (x == 0)
        return x;
    while(x != 0)
    {
        int getN = x % 10;
        if(res > INT_MAX/10 || res<INT_MIN/10)
        {
            return 0;
        }
        res = res * 10 + getN;
        x = x / 10;

    }
    return res;
}

int main()
{
    int x = -206;
    int y = reverse(x);
    cout << y << endl;



    system("pause");
    return 0;
}
