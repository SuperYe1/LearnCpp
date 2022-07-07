/*
 * @lc app=leetcode.cn id=498 lang=cpp
 *
 * [498] 对角线遍历
 */

// @lc code=start
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> res;
        int i = 0, j = 0;
        bool isTurnUp = true;
        while (i != m-1 || j != n-1)
        {
            res.push_back(mat[i][j]);
            if(isTurnUp)
            {
                i--;
                j++;
                if(i<0 && j<n)
                {
                    i = 0;
                    isTurnUp = !isTurnUp;
                }
                else if(j==n)
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
                if(i==m)
                {
                    i = m - 1;
                    j = j + 2;
                    isTurnUp = !isTurnUp;
                }
                else if(i <m && j<0)
                {
                    j = 0;
                    isTurnUp = !isTurnUp;
                }
            }
        }
        res.push_back(mat[i][j]);
        return res;
    }
};
// @lc code=end

