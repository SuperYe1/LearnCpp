#include "oftenUse.hpp"
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class MagicDictionary
{
private:
    unordered_map<int, vector<string>> map;

    bool isChangeOneWord(string str1, string str2)
    {
        int len = str1.size();
        bool dif = false;
        for(int i = 0; i < len; i++)
        {
            if(str1[i] != str2[i])
            {
                if(dif)
                    return false;
                dif = true;
            }
            
        }
        return dif;
    }

public:
    MagicDictionary()
    {
        map = unordered_map<int, vector<string>>();
    }

    void buildDict(vector<string> dictionary)
    {
        for(auto str:dictionary)
        {
            int len = str.size();
            map[len].push_back(str);
        }
    }

    bool search(string searchWord)
    {
        int len = searchWord.size();
        for(auto it = map.begin(); it != map.end(); it++)
        {
            if (it->first == len)
            {
                for (auto it2 : it->second)
                {
                    if(isChangeOneWord(it2,searchWord))
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{

    system("pause");
    return 0;
}