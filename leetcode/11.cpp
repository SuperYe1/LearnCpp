#include <iostream>
using namespace std;
#include <vector>

int maxArea(vector<int> &height)
{
    // int max_volumn = 0;
    // int volumn = 0;
    // for (int i = 0; i < height.size() - 1; i++)
    // {
    //     for (int j = i; j < height.size(); j++)
    //     {
    //         volumn = min(height[i], height[j]) * (j - i);
    //         max_volumn = max(volumn, max_volumn);
    //     }
    // }
    // return max_volumn;

    int i = 0, j = height.size() - 1;
    int volumn, max_volumn(0);
    while (i < j)
    {
        volumn = min(height[i], height[j]) * (j - i);
        max_volumn = max(volumn, max_volumn);
        if (height[i] < height[j])
            i++;
        else
            j--;
    }
    return max_volumn;
}
int main()
{
    vector<int> p;
    p = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int a = maxArea(p);

    cout << a << endl;

    system("pause");
    return 0;
}
