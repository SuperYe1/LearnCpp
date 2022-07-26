#include "oftenUse.hpp"
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int minCostToMoveChips(vector<int> &position)
{
    int evennum = 0, oddnum = 0;
    for(int pos:position)
    {
        if(pos%2)
            oddnum++;
        else
            evennum++;
    }
    return min(evennum,oddnum);
    
}
int main()
{

    system("pause");
    return 0;
}