#include "oftenUse.hpp"
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int intersectionSizeTwo(vector<vector<int>> &intervals)
{
    int ans = 2;
    int len = intervals.size();
    if (len == 1)
        return ans;
    sort(intervals.begin(), intervals.end(),
         [](const vector<int> &a, const vector<int> &b)
         {
             return (a[0] < b[0]) || ((a[0] == b[0]) && (a[1] > b[1]));
         });
    vector<vector<int>> stremLine;
    stremLine.push_back(intervals[len - 1]);
    for (int i = len - 2; i >= 0; i--)
    {
        auto temp = stremLine.back();
        if (intervals[i][1] > temp[0])
        {
            //stremLine.pop_back();
            //stremLine.push_back({max(temp[0], intervals[i][0]), min(temp[1], intervals[i][1])});
            continue;
        }
        stremLine.push_back(intervals[i]);
    }
    if (stremLine.size() == 1)
        return ans;
    for (int i = stremLine.size() - 2; i >= 0; i--)
    {
        if (stremLine[i][0] == stremLine[i + 1][1])
            ans += 1;
        else
            ans += 2;
    }
    return ans;
}
int main()
{
    vector<vector<int>> intervals = {{1, 3},
                                     {4, 9},
                                     {0, 10},
                                     {6, 7},
                                     {1, 2},
                                     {0, 6},
                                     {7, 9},
                                     {0, 1},
                                     {2, 5},
                                     {6, 8}};
    // vector<vector<int>> intervals = {{2,15},
    //                                  {9,17},
    //                                  {0,6},
    //                                  {17,25},
    //                                  {0,25}};
    int len = intervals.size();
    sort(intervals.begin(), intervals.end(),
         [](const vector<int> &a, const vector<int> &b)
         {
             return (a[0] < b[0]) || ((a[0] == b[0]) && (a[1] > b[1]));
             ;
         });
    vector<vector<int>> stremLine;
    // for (int i = 0; i < intervals.size(); i++)
    // {
    //     int j = i;
    //     int minR = intervals[i][1];
    //     while (j < intervals.size() && intervals[j][0] < minR)
    //     {
    //         minR = min(minR, intervals[j][1]);
    //         j++;
    //     }
    //     stremLine.push_back({intervals[--j][0], minR});
    //     i = j;
    // }
    stremLine.push_back(intervals[len - 1]);
    for (int i = len - 2; i >= 0; i--)
    {
        auto temp = stremLine.back();
        if (intervals[i][1] > temp[0])
        {
            //stremLine.pop_back();
            //stremLine.push_back({max(temp[0], intervals[i][0]), min(temp[1], intervals[i][1])});
            continue;
        }
        stremLine.push_back(intervals[i]);
    }
    for (auto interval : intervals)
    {
        cout << interval[0] << " " << interval[1] << endl;
    }
    cout << "==============" << endl;
    for (auto interval : stremLine)
    {
        cout << interval[0] << " " << interval[1] << endl;
    }
    cout << intersectionSizeTwo(intervals) << endl;
    system("pause");
    return 0;
}