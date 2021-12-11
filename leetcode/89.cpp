#include <iostream>
#include <vector>
using namespace std;

vector<int> grayCode(int n)
{
    vector<int> res;
    for (int i = 0; i < 1 << n; ++i)
    {
        res.push_back(i ^ i >> 1);
        cout << res[i] << endl;
    }
    return res;
}

int main()
{
    cout << (7 >> 1) << endl;
    // vector<int> res = grayCode(2);
    system("pause");
    return 0;
}
