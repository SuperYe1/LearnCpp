#include <iostream>
using namespace std;
#include <vector>

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    vector<vector<int>> res;
    bool place = false;
    int left = newInterval[0];
    int right = newInterval[1];
    for (int i = 0; i < intervals.size(); i++)
    {
        if (intervals[i][1] < left)
        {
            res.push_back(intervals[i]);
        }
        else if (intervals[i][0] > right)
        {
            if (!place)
            {
                res.push_back({left, right});
                place = true;
            }
            res.push_back(intervals[i]);
        }
        else
        {
            left = min(intervals[i][0], left);
            right = max(intervals[i][1], right);
        }
    }
    if (!place)
        res.push_back({left, right});
    return res;
}
int main()
{

    system("pause");
    return 0;
}
