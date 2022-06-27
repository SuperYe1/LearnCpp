#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
private:
    unordered_map<int, int> writeMap;
    int bound;

public:
    Solution(int n, vector<int> &blacklist)
    {
        int m = blacklist.size();
        bound = n - m;
        unordered_map<int, int> black;
        for(int i:blacklist)
        {
            if(i>=bound)
                black[i]++;
        }
        int w = bound;
        for(int i:blacklist)
        {
            if(i<bound)
            {
                while(black.find(w)!=black.end())
                    w++;
                writeMap[i] = w++;
            }
        }
    }

    int pick()
    {
        int res = rand() % bound;
        return writeMap.count(res)?writeMap[res]:res;
    }
};

int main()
{

    system("pause");
    return 0;
}