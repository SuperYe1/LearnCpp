#include <iostream>
using namespace std;
#include <algorithm>;
#include <vector>;

int lengthOfLongestSubstring(string s)
{
    int length = 0;
    int result = 0;
    int t = 0, i = 0;
    while (i < int(s.size()))
    {
        char tmpChar = s[i];
        for (int j = t; j < i;j++)
        {
            if(tmpChar == s[j])
            {
                t = j + 1;
                length = i - t;

                break;
            }
        }
        length++;
        i++;
        result = max(result, length);
    }

    return result;

}
int main()
{

    string s = "abcabcbb";
    int b = lengthOfLongestSubstring(s);
    cout << s << endl;
    cout << b << endl;
    system("pause");
    return 0;
}
