#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    if (intervals.size() == 0)
        return {};
    sort(
        intervals.begin(), intervals.end(), [&](vector<int> x, vector<int> y) {
            if (x[0] <= y[0])
                return true;
            return false;
        });
    vector<vector<int>> res;
    for (int i = 0; i < intervals.size(); i++)
    {
        int left = intervals[i][0], right = intervals[i][1];
        if(res.size() == 0||res.back()[1]<left)
        {
            res.push_back({left,right});
        }
        else{
            res.back()[1] = max(res.back()[1],right);
        }
    }
    return res;
}
int main()
{
    vector<vector<int>> intervals = {{1, 3}, {21, 25}, {8, 10}, {15, 18}};
    sort(
        intervals.begin(), intervals.end(), [&](vector<int> x, vector<int> y) {
            if (x[0] <= y[0])
                return true;
            return false;
        });
    for (int i = 0; i < intervals.size(); i++)
    {
        for (int j = 0; j < intervals[i].size(); j++)
            cout << intervals[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    system("pause");
    return 0;
}
