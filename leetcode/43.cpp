#include <iostream>
using namespace std;
#include <cmath>
#include<algorithm>

string multiply(string num1, string num2)
{
    int a = 0;
    int b = 0;
    if (num1 == "0" || num2 == "0")
        return "0";
    int n1 = num1.size();
    int n2 = num2.size();
    for (int i = 0; i < n1;i++)
    {
        a += (num1[i]-'0') * pow(10, n1 - i - 1);
    }
    for (int i = 0; i < n2;i++)
    {
        b += (num2[i]-'0') * pow(10, n2 - i - 1);
    }
    int c = a * b;
    int temp =c;
    int index = 0;
    string str;
    while(temp>=10)
    {
        index++;
        str.push_back(temp%10+'0');
        temp = temp / 10;
    }
    str.push_back(temp%10+'0');
    reverse(str.begin(),str.end());
    return str;
}

int main()
{
    string num1 = "2";
    string num2 = "3";

    int a = 0;
    int b = 0;
    // if (num1 == "0" || num2 == "0")
    //     return "0";
    int n1 = num1.size();
    int n2 = num2.size();
    for (int i = 0; i < n1;i++)
    {
        a += (num1[i]-'0') * pow(10, n1 - i - 1);
    }
    for (int i = 0; i < n2;i++)
    {
        b += (num2[i]-'0') * pow(10, n2 - i - 1);
    }
    int c = a * b;
    int temp =c;
    int index = 0;
    string str;
    while(temp>=10)
    {
        index++;
        str.push_back(temp%10+'0');
        temp = temp / 10;
    }
    str.push_back(temp%10+'0');
    reverse(str.begin(),str.end());
    cout << c<<" "<<index << endl;

    string str1 = multiply(num1, num2);


    cout << str1 << endl;

    system("pause");
    return 0;
}
