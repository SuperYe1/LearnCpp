#include <iostream>
#include <vector>
using namespace std;

/*


*/

vector<int> findDiagonalOrder(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();
    vector<int> res;
    int i = 0, j = 0;
    bool isTurnUp = true;
    while (i != m - 1 || j != n - 1)
    {
        res.push_back(mat[i][j]);
        if (isTurnUp)
        {
            i--;
            j++;
            if (i < 0 && j < n)
            {
                i = 0;
                isTurnUp = !isTurnUp;
            }
            else if (i < 0 && j == n)
            {
                i = 1;
                j = n - 1;
                isTurnUp = !isTurnUp;
            }
            else if (i >= 0 && j == n)
            {
                i = i + 2;
                j = n - 1;
                isTurnUp = !isTurnUp;
            }
        }
        else
        {
            i++;
            j--;
            if (i == m && j < 0)
            {
                i = m - 1;
                j = 1;
                isTurnUp = !isTurnUp;
            }
            else if (i == m && j >= 0)
            {
                i = m - 1;
                j = j + 2;
                isTurnUp = !isTurnUp;
            }
            else if (i < m && j < 0)
            {
                j = 0;
                isTurnUp = !isTurnUp;
            }
        }
    }
    res.push_back(mat[i][j]);
    return res;
}
int main()
{
    vector<int> a = {1, 2, 3};
    vector<vector<int>> mat;
    mat.push_back(a);
    a = {4,5,6};
    mat.push_back(a);
    a = {7,8,9};
    mat.push_back(a);
    a = findDiagonalOrder(mat);

    return 0;
}