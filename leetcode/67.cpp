#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string addBinary(string a, string b)
{
    int i = a.size()-1;
    int j = b.size()-1;
    int other = 0;
    string res;
    while (i >= 0 && j >= 0)
    {
        int a1 = a[i] - '0';
        int b1 = b[j] - '0';
        char c = (a1 + b1 + other) % 2 + '0';
        other = (a1 + b1 + other) / 2;
        res.push_back(c);
        i--;
        j--;
    }
    while (i >= 0)
    {
        int a1 = a[i] - '0';
        char c = (a1 + other) % 2 + '0';
        other = (a1 + other) / 2;
        res.push_back(c);
        i--;
    }
    while (j >= 0)
    {
        int b1 = b[j] - '0';
        char c = (b1 + other) % 2 + '0';
        other = (b1 + other) / 2;
        res.push_back(c);
        j--;
    }
    if (other == 1)
        res.push_back('1');
    reverse(res.begin(), res.end());
    return res;
}

int main()
{

    system("pause");
    return 0;
}
