#include "oftenUse.hpp"
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool canBeEqual(vector<int> &target, vector<int> &arr)
{
    unordered_map<int, int> m1, m2;
    int n = target.size();
    if(arr.size()!=n)
        return false;
    for(int i = 0; i < n; i++)
    {
        m1[target[i]]++;
        m2[arr[i]]++;
    }
    if(m1.size()!=m2.size())
        return false;
    for(auto &[key,value]:m1)
    {
        if(m2[key]!=value)
            return false;
    }
    return true;
}
int main()
{
    unordered_map<int, int> m1, m2;
    cout << m1[0] << endl;
    system("pause");
    return 0;
}