#include "oftenUse.hpp"
#include <cfloat>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
{
    int n = quality.size();
    double mincost = DBL_MAX;
    vector<int> wageUp(n,0);
    
    return mincost;
}

int main()
{
    vector<int> qua = {3,1,10,10,1};
    vector<int> wage = {4,8,2,2,7};
    cout << mincostToHireWorkers(qua, wage, 3) << endl;
    system("pause");
    return 0;
}