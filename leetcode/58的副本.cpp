#include <iostream>
using namespace std;
#include <vector>

int lengthOfLastWord(string s)
{
    int num = 0;
    for (int i = s.size()-1; i >= 0; i--)
    {
        if (s[i] != ' ')
            num++;
        if (s[i] == ' ' && num > 0)
            return num;
    }
    return num;
}
int main()
{

    system("pause");
    return 0;
}
