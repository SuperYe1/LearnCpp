#include "oftenUse.hpp"
#include <iostream>
#include <vector>
using namespace std;

int oddCells(int m, int n, vector<vector<int>> &indices)
{
    int cow[n] = {0};
    int list[m] = {0};
    int oddx = 0, oddy = 0;
    for(auto indice:indices)
    {
        list[indice[0]]++;
        cow[indice[1]]++;
    }
    for(auto i:cow)
    {
        if (i&1)
            oddx++;
    }
    for(auto i:list)
    {
        if (i&1)
            oddy++;
    }
    return oddx*(m-oddy)+oddy*(n-oddx);
}

int main()
{

    system("pause");
    return 0;
}