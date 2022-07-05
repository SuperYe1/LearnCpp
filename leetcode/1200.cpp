#include "oftenUse.hpp"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> minimumAbsDifference(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> res;
    int nowDiff = INT_MAX;
    for (int i = 1; i < arr.size(); i++)
    {
        int temp = arr[i] - arr[i - 1];
        if (temp < nowDiff)
        {
            res = vector<vector<int>>();
            nowDiff = temp;
        }
        else if (temp > nowDiff)
            continue;
        res.push_back({arr[i - 1], arr[i]});
    }
    return res;
}

int main()
{

    system("pause");
    return 0;
}