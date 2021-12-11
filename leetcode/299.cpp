#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
299. 猜数字游戏

你在和朋友一起玩 猜数字（Bulls and Cows）游戏，该游戏规则如下：

写出一个秘密数字，并请朋友猜这个数字是多少。朋友每猜测一次，
你就会给他一个包含下述信息的提示：
猜测数字中有多少位属于数字和确切位置都猜对了（称为 "Bulls", 公牛），
有多少位属于数字猜对了但是位置不对（称为 "Cows", 奶牛）。
也就是说，这次猜测中有多少位非公牛数字可以通过重新排列转换成公牛数字。
给你一个秘密数字 secret 和朋友猜测的数字 guess ，
请你返回对朋友这次猜测的提示。

提示的格式为 "xAyB" ，x 是公牛个数， y 是奶牛个数，A 表示公牛，B 表示奶牛。

请注意秘密数字和朋友猜测的数字都可能含有重复数字。
*/

string getHint(string secret, string guess)
{
    int num = secret.size();
    unordered_map<int, int> m1, m2;
    int numx = 0;
    int numy = 0;
    string ans;
    for (int i = 0; i < num; i++)
    {
        if (secret[i] == guess[i])
            numx++;
        else
        {
            m1[secret[i]]++;
            m2[guess[i]]++;
        }
    }
    for (auto y = m1.begin(); y != m1.end();y++)
    {
        numy += min(m1[y->first],m2[y->first]);
    }
    ans = to_string(numx) + "A" + to_string(numy) + "B";
    return ans;
}
int main()
{
    string a = "111111111111111111";
    string b = "111111111111110000";
    cout << getHint(a, b) << endl;

    return 0;
}