#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();
    if (m * n == 0 || target < matrix[0][0] || target > matrix[m - 1][n - 1])
        return false;
    int left = 0, right = m * n - 1, mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (matrix[mid / n][mid % n] < target)
            left = mid + 1;
        else if (matrix[mid / n][mid % n] > target)
            right = mid - 1;
        else
            return true;
    }

    return false;
}
int main()
{

    system("pause");
    return 0;
}
