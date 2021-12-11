#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

// 求阶乘
int fx(int n)
{
    int res = n;
    while(n>1)
    {
        n--;
        res = res * n;
    }
    return res;
}

void strpush(int k, int n, string &str, string &s)
{
    if (k == 0)
    {
        reverse(str.begin(), str.end());
        s += str;
        return;
    }
    if (k == 1)
    {
        s += str;
        return;
    }
    int temp = k / fx(n - 1);
    if (k % fx(n - 1) == 0)
    {
        s.push_back(str[temp - 1]);
        str.erase(temp - 1, 1);
    }
    else
    {
        s.push_back(str[temp]);
        str.erase(temp, 1);
    }
}
string getPermutation(int n, int k)
{
    int m = n;
    string str;
    for (int i = 0; i < n; i++)
        str.push_back(i + '1');
    string res;
    while (true)
    {
        strpush(k, n, str, res);
        if(res.size()==m)
            break;
        k = k % fx(n - 1);
        n--;

    }
    return res;
}

int main()
{
    int n = 8;
    string res;



    res = getPermutation(3, 3);
    cout << res << endl;
    // for (int i = 0; i < n; i++)
    //     str.push_back(i + '1');
    // // str.erase(5 , 1);
    // reverse(str.begin(), str.end());
    // swap(str[0], str[5]);
    // cout << str << endl;
    // int n = 4;
    // cout << fx(4) << endl;
    system("pause");
    return 0;
}
