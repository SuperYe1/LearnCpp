#include <iostream>
#include <vector>
using namespace std;

int totalHammingDistance(vector<int> &nums)
{
    int ans = 0, n = nums.size();
    for (int i = 0; i < 30; i++)
    {
        int c = 0;
        for (int val : nums)
        {
            c += (val >> i) & 1;
        }
        ans += c * (n - c);
    }
    return ans;
}
int main()
{

    system("pause");
    return 0;
}