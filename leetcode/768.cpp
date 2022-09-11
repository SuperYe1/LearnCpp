#include<iostream>
#include<vector>
#include "oftenUse.hpp"
using namespace std;

int maxChunksToSorted(vector<int>& arr)
{
    int res = 0;
    int tempMax = arr[0], tempMin = arr[0];
    vector<pair<int, int>> extreValue;
    for(int i = 1; i < arr.size(); i++)
    {
        if(arr[i]>=tempMax)
        {
            extreValue.push_back({tempMin, tempMax});
            res++;
            tempMin = arr[i];
            tempMax = arr[i];
        }
    }

}

int main()
{

    
    system("pause");
    return 0;
}