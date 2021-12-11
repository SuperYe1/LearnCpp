#include <iostream>
using namespace std;
#include <vector>

int maxProfit(vector<int> &prices)
{
    int res = 0;
    int first;
    int second = -1;
    while (first < prices.size() - 1)
    {
        if (second < 0 && prices[first] < prices[first + 1])
        {
            second = first;
            first++;
            continue;
        }
        if (second > 0 && prices[first] > prices[first + 1])
        {
            res = res + prices[first] - prices[second];
            second = -1;
            first++;
            continue;
        }
        first++;
    }
    if (second > 0)
        res = res + prices[first] - prices[second];
    return res;
}

int main()
{

    system("pause");
    return 0;
}
