#include <iostream>
using namespace std;
#include <vector>

int uniquePaths(int m, int n)
{
    int N = n + m - 2;
    double res = 1;
    for (int i = 1; i < m; i++)
        res = res * (N - (m - 1) + i) / i;
    return (int) res;
}
int main()
{

    system("pause");
    return 0;
}
