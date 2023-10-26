#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1109 lang=cpp
 *
 * [1109] Corporate Flight Bookings
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
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
    {
        vector<int> nums(n);
        Difference diff(nums);
        for (vector<int> booking : bookings)
        {
            int l = booking[0] - 1;
            int r = booking[1] - 1;
            int val = booking[2];
            diff.increase(l, r, val);
        }
        return diff.result();
    }
};
// @lc code=end
