#include <iostream>
using namespace std;
#include <vector>

int isNum(char c)
{
    if (c >= '0' && c <= '9')
        return 2;
    else
        return 5;
}
int rNum(char c)
{
    switch (c)
    {
    case ' ':
        return 0;
    case '+':
        return 1;
    case '-':
        return 1;
    case 'e':
        return 4;
    case '.':
        return 3;
    default:
        return isNum(c);
    }
}
bool isNumber(string s)
{
    if (s.empty())
        return false;
    int n = s.size();
    int state = 0;
    vector<bool> finals({0, 0, 0, 1, 0, 1, 1, 0, 1});
    vector<vector<int>> transfer({
        {0, 1, 6, 2, -1, -1},
        {-1, -1, 6, 2, -1, -1},
        {-1, -1, 3, -1, -1, -1},
        {8, -1, 3, -1, 4, -1},
        {-1, 7, 5, -1, -1, -1},
        {8, -1, 5, -1, -1, -1},
        {8, -1, 6, 3, 4, -1},
        {-1, -1, 5, -1, -1, -1},
        {8, -1, -1, -1, -1, -1},
    });
    for (int i = 0; i < n; i++)
    {
        state = transfer[state][rNum(s[i])];
        if (state < 0)
            return false;
    }
    return finals[state];
}

int main()
{

    system("pause");
    return 0;
}
