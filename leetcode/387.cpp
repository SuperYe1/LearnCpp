#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int firstUniqChar(string s)
{
    int arr[26] = {0};
    for(char c:s)
        arr[c-'a']++;
    for(int i=0; i<s.size(); i++)
    {
        if(arr[s[i]-'a']==1)
            return i;
    }
    return -1;
}

int main()
{
    
    system("pause");
    return 0;
}