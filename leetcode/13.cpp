#include <iostream>
using namespace std;

int myFun(char c)
{
    switch (c)
    {
    case 'I':
        return 1;
        break;
    case 'V':
        return 5;
        break;
    case 'X':
        return 10;
        break;
    case 'L':
        return 50;
        break;
    case 'C':
        return 100;
        break;
    case 'D':
        return 500;
        break;
    case 'M':
        return 1000;
        break;
        default:
            return 0;
    }
}
int romanToInt(string s)
{

    int index = 0;
    int num = 0;
    while (index < s.size())
    {
        if (s[index] == 'C')
        {
            if (s[index + 1] == 'D')
            {
                num += 400;
                index = index + 2;
            }
            else if (s[index + 1] == 'M')
            {
                num += 900;
                index = index + 2;
            }
            else
            {
                num += 100;
                index = index + 1;
            }

        }
        else if(s[index] == 'X')
        {
            if (s[index + 1] == 'L')
            {
                num += 40;
                index = index + 2;
            }
            else if (s[index + 1] == 'C')
            {
                num += 90;
                index = index + 2;
            }
            else
            {
                num += 10;
                index = index + 1;
            }
        }
        else if(s[index] == 'I')
        {
            if (s[index + 1] == 'V')
            {
                num += 4;
                index = index + 2;
            }
            else if (s[index + 1] == 'X')
            {
                num += 9;
                index = index + 2;
            }
            else
            {
                num += 1;
                index = index + 1;
            }
        }
        else
        {
            num += myFun(s[index]);
            index++;
        }

    }
    return num;
}
int main()
{
    string s = "LVIII";
    int a = romanToInt(s);
    cout << a << endl;
    system("pause");
    return 0;
}
