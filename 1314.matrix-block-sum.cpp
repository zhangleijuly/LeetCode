#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1314 lang=cpp
 *
 * [1314] Matrix Block Sum
 */

// @lc code=start
class Solution
{
  public:
    vector<vector<int>> preSum;
    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k)
    {
        preSum = vector<vector<int>>(mat.size() + 1, vector<int>(mat[0].size() + 1, 0));
        vector<vector<int>> res = vector<vector<int>>(mat.size(), vector<int>(mat[0].size(), 0));
        for (int i = 0; i < mat.size(); ++i)
        {
            for (int j = 0; j < mat[0].size(); ++j)
            {
                preSum[i + 1][j + 1] = preSum[i][j + 1] + preSum[i + 1][j] + mat[i][j] - preSum[i][j];
            }
        }
        for (int i = 0; i < mat.size(); ++i)
        {
            for (int j = 0; j < mat[0].size(); ++j)
            {
                int row1 = (i - k >= 0) ? i - k : 0;
                int col1 = (j - k >= 0) ? j - k : 0;
                int row2 = (i + k < mat.size()) ? i + k : mat.size() - 1;
                int col2 = (j + k < mat[0].size()) ? j + k : mat[0].size() - 1;
                res[i][j] =
                    preSum[row2 + 1][col2 + 1] - preSum[row2 + 1][col1] - preSum[row1][col2 + 1] + preSum[row1][col1];
            }
        }
        return res;
    }
};
// @lc code=end
