#include <iostream>
#include <vector>
using namespace std;

/*
796. 旋转字符串

给定两个字符串, s 和 goal。如果在若干次旋转操作之后，
s 能变成 goal ，那么返回 true 。
s 的 旋转操作 就是将 s 最左边的字符移动到最右边。 
例如, 若 s = 'abcde'，在旋转一次之后结果就是'bcdea' 。
*/

bool isStr(string parent, string son)
{
    if(son.size()>parent.size())
        return false;
    for (int i = 0; i <= parent.size() - son.size();i++)
    {
        if(parent[i] == son[0])
        {
            int j = 0;
            for (j = 0; j < son.size(); j++)
            {
                if(parent[i+j] != son[j])
                    break;
            }
            if(j == son.size())
                return true;
        }
    }
    return false;
}
bool rotateString(string s, string goal)
{
    if(s.size()!=goal.size())
        return false;
    return isStr(s+s,goal);
}
int main()
{
    cout << rotateString("abcde", "cdebb") << endl;

    return 0;
}