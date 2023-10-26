#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1094 lang=cpp
 *
 * [1094] Car Pooling
 */

// @lc code=start
class Difference
{
  private:
    vector<int> diff;

  public:
    Difference(vector<int> nums)
    {
        if (!nums.empty())
        {
            int n = nums.size();
            diff = vector<int>(n);
            diff[0] = nums[0];
            for (int i = 1; i < n; ++i)
            {
                diff[i] = nums[i] - nums[i - 1];
            }
        }
    }
    void increase(int l, int r, int val)
    {
        diff[l] += val;
        if (r + 1 < diff.size())
        {
            diff[r + 1] -= val;
        }
    }
    vector<int> result()
    {
        vector<int> res(diff.size());
        res[0] = diff[0];
        for (int i = 1; i < diff.size(); ++i)
        {
            res[i] = res[i - 1] + diff[i];
        }
        return res;
    }
};
class Solution
{
  public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        vector<int> nums(1001);
        Difference diff(nums);
        for (vector<int> trip : trips)
        {
            int val = trip[0];
            int l = trip[1];
            int r = trip[2] - 1;
            diff.increase(l, r, val);
        }
        vector<int> res = diff.result();
        for (int i : res)
        {
            if (i > capacity)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
