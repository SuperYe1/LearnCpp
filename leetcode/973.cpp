#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
{
    vector<vector<int>> res;
    sort(points.begin(), points.end(), [&](vector<int> x, vector<int> y) {
        double a = x[0] * x[0] + x[1] * x[1];
        double b = y[0] * y[0] + y[1] * y[1];
        return a <= b;
    });
    for (int i = 0; i < K; i++)
    {
        res.push_back(points[i]);
    }
    return res;
}

int main()
{

    system("pause");
    return 0;
}
