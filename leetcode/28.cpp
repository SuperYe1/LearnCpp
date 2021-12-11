#include <iostream>
using namespace std;

int strStr(string haystack, string needle)
{
    if (needle.size() == 0)
        return 0;
    if(haystack.size()<needle.size())
        return -1;

    for (int i = 0; i < haystack.size()-needle.size()+1; i++)
    {
        if (haystack[i] == needle[0])
        {
            int j = 0;
            while (i + j < haystack.size() && haystack[i + j] == needle[j])
            {
                j++;
            }
            if (j == needle.size())
                return i;
        }
    }
    return -1;
}
int main()
{
    string a = "hello";
    string b = "ll";
    cout << strStr(a, b) << endl;
    system("pause");
    return 0;
}
