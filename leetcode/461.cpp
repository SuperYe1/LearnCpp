#include <iostream>
#include <vector>
using namespace std;

int hammingDistance(int x, int y)
{
    int set = x ^ y, ret = 0;
    while (set)
    {
        ret += set & 1;
        set >>= 1;
    }
    return ret;
}

int main()
{

    system("pause");
    return 0;
}
