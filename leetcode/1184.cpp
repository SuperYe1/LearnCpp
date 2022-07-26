#include "oftenUse.hpp"
#include <iostream>
#include <vector>
using namespace std;

int distanceBetweenBusStops(vector<int> &distance, int start, int destination)
{
    int n = distance.size();
    if (start == destination)
        return 0;
    int minS = min(start, destination);
    int maxS = max(start, destination);
    int lena = 0, lenb = 0;
    for (int i = 0; i < n; i++)
    {
        if (i < minS || i >= maxS)
            lena += distance[i];
        else
            lenb += distance[i];
    }
    return min(lena, lenb);
}
int main()
{
    vector<int> distance = {1, 2, 3, 4};
    cout << distanceBetweenBusStops(distance, 0, 1) << endl;
    system("pause");
    return 0;
}