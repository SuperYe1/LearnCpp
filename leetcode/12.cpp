#include <iostream>
using namespace std;
#include <cmath>
#include <vector>

string myFunc(int x)
{
    switch (x)
    {
    case 1:
        return "I";
        break;
    case 2:
        return "II";
        break;
    case 3:
        return "III";
        break;
    case 6:
        return "VI";
        break;
    case 7:
        return "VII";
        break;
    case 8:
        return "VIII";
    }
}

string intToRoman(int num)
{
    if (num < 1 || num > 3999)
        return "0";
    string roman;
    int nNum = 0;
    int temp = num;

    while (temp)
    {
        nNum++;
        temp = temp / 10;
    }

    vector<int> n;
    temp = num;
    int i = nNum - 1;
    while (temp)
    {
        int x = temp / pow(10, i);
        n.push_back(x);
        temp = temp - x * pow(10, i);
        i--;
    }
    int index = 0;
    if (n.size() > 3)
    {
        while (n[index] != 0)
        {
            roman += 'M';
            n[index]--;
        }
        index++;
        if (n[index] == 4)
            roman += "CD";
        else if (n[index] == 5)
            roman += "D";
        else if (n[index] == 9)
            roman += "CM";
        else
            roman += myFunc(n[index]);
        index++;
        if (n[index] == 4)
            roman += "XL";
        else if (n[index] == 5)
            roman += "L";
        else if (n[index] == 9)
            roman += "XC";
        else
            roman += myFunc(n[index]);
        index++;
        if (n[index] == 4)
            roman += "IV";
        else if (n[index] == 5)
            roman += "V";
        else if (n[index] == 9)
            roman += "IX";
        else
            roman += myFunc(n[index]);
    }
    else if (n.size() > 2)
    {
        if (n[index] == 4)
            roman += "CD";
        else if (n[index] == 5)
            roman += "D";
        else if (n[index] == 9)
            roman += "CM";
        else
            roman += myFunc(n[index]);
        index++;
        if (n[index] == 4)
            roman += "XL";
        else if (n[index] == 5)
            roman += "L";
        else if (n[index] == 9)
            roman += "XC";
        else
            roman += myFunc(n[index]);
        index++;
        if (n[index] == 4)
            roman += "IV";
        else if (n[index] == 5)
            roman += "V";
        else if (n[index] == 9)
            roman += "IX";
        else
            roman += myFunc(n[index]);
    }
    else if (n.size() > 1)
    {
        if (n[index] == 4)
            roman += "XL";
        else if (n[index] == 5)
            roman += "L";
        else if (n[index] == 9)
            roman += "XC";
        else
            roman += myFunc(n[index]);
        index++;
        if (n[index] == 4)
            roman += "IV";
        else if (n[index] == 5)
            roman += "V";
        else if (n[index] == 9)
            roman += "IX";
        else
            roman += myFunc(n[index]);
    }
    else
    {
        if (n[index] == 4)
            roman += "IV";
        else if (n[index] == 5)
            roman += "V";
        else if (n[index] == 9)
            roman += "IX";
        else
            roman += myFunc(n[index]);
    }
    return roman;
}

int main()
{
    int num = 58;
    string s = intToRoman(num);
    cout << s << endl;

    system("pause");
    return 0;
}
