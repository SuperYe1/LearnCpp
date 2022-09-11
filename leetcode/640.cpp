#include "oftenUse.hpp"
#include <iostream>
#include <vector>
using namespace std;

bool isNum(char c)
{
    return (c >= '0' && c <= '9');
}

int getNum(const string equation, int &index)
{
    int ans = 0;
    while (index < equation.size() && isNum(equation[index]))
    {
        ans = ans * 10 + equation[index] - '0';
        index++;
    }
    return ans;
}

string solveEquation(string equation)
{
    int index = 0, numx = 0, numint = 0;
    int isadd = 1, eqdir = 1;
    pair<int, bool> temp = {0, false};
    while (index < equation.size())
    {
        if (isNum(equation[index]))
        {
            temp.first = getNum(equation, index);
            temp.second = true;
            continue;
        }
        switch (equation[index])
        {
        case 'x':
            if (temp.second)
                numx += temp.first * isadd * eqdir;
            else
                numx += isadd * eqdir;
            break;
        case '+':
            numint += temp.first * isadd * eqdir;
            
            isadd = 1;
            break;
        case '-':
            numint += temp.first * isadd * eqdir;
            isadd = -1;
            break;
        case '=':
            numint += temp.first * isadd * eqdir;
            isadd = 1;
            eqdir = -1;
            break;
        }
        temp = {0, false};
        index++;
    }
    numint += temp.first * isadd * eqdir;
    if(numx == 0)
            return numint == 0 ?"Infinite solutions" : "No solution";
    return "x=" + to_string(-1*numint / numx);
}

int main()
{
    string equation = "2x=x";
    cout<<solveEquation(equation)<<endl;
    system("pause");
    return 0;
}