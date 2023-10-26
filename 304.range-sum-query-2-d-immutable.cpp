#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */

// @lc code=start
class NumMatrix
{
  public:
    vector<vector<int>> preSum;
    NumMatrix(vector<vector<int>> &matrix)
    {
        preSum = vector<vector<int>>(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                preSum[i + 1][j + 1] = preSum[i][j + 1] + preSum[i + 1][j] + matrix[i][j] - preSum[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return preSum[row2 + 1][col2 + 1] - preSum[row2 + 1][col1] - preSum[row1][col2 + 1] + preSum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
