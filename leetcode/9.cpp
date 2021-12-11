#include <iostream>
using namespace std;
#include <cmath>
#include <vector>

bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    if (x == 0)
        return true;
    int xnum = 0;
    int temp = x;
    while (temp)
    {
        xnum++;
        temp = temp / 10;
    }
    vector<int> v(xnum);
    temp = x;
    for (int i = 0; i < xnum; i++)
    {
        // v[i] = (temp / (pow(10, xnum -i-1)));
        // temp = temp - v[i] * pow(10, xnum -i-1);
        v[i] = temp % 10;
        temp = temp / 10;
    }
    for (int i = 0; i < xnum/2; i++)
    {
        if (v[i] == v[xnum - i-1])
            continue;
        else
            return false;
    }
    return true;
    // return v;
}
int main()
{
    int x;
    // cin >> x;
    // vector<int> v = isPalindrome(x);
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i];
    // }
    // cout << endl;

    cin >> x;
    bool y = isPalindrome(x);
    if (y)
        cout << "是回文数" << endl;
    else
        cout << "不是回文数" << endl;

    system("pause");
    return 0;
}
