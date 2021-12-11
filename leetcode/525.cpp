#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int findMaxLength(vector<int> &nums)
{
    int counter = 0;
    int maxLength = 0;
    unordered_map<int, int> m;
    m[counter] = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
            counter++;
        else
            counter--;
        if (m.count(counter))
        {
            int pre = m[counter];
            maxLength = max(maxLength, i - pre);
        }
        else
        m[counter] = i;
    }
    return maxLength;
}
int main()
{

    system("pause");
    return 0;
}
