#include <iostream>
#include <vector>
using namespace std;

bool xorGame(vector<int> &nums)
{
    if (nums.size() % 2 == 0)
        return true;
    int temp = 0;
    for (int i : nums)
        temp ^= i;
    return temp == 0;
}

int main()
{

    system("pause");
    return 0;
}
