#include "oftenUse.hpp"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    vector<int> ans;
    int n = arr.size();
    int right = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    int left = right - 1;
    while(k--)
    {
        if(left < 0)
            right++;
        else if(right>=n)
            left--;
        else if(x-arr[left]<=arr[right]-x)
            left--;
        else
            right++;
    }
    ans.assign(arr.begin()+left+1, arr.begin()+right);
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 3, 3,3,3,4, 5};
    vector<int> temp = findClosestElements(arr, 4, 3);
    for(int i = 0; i < temp.size(); i++)
        cout << temp[i] << " ";
    cout << endl;
    system("pause");
    return 0;
}