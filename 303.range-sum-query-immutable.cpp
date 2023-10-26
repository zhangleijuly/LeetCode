#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */

// @lc code=start
class NumArray
{
  public:
    vector<int> preSum;
    NumArray(vector<int> &nums)
    {
        preSum = vector<int>(nums.size() + 1);
        for (int i = 0; i < nums.size(); ++i)
        {
            preSum[i + 1] = preSum[i] + nums[i];
        }
    }

    int sumRange(int left, int right)
    {
        return preSum[right + 1] - preSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end
