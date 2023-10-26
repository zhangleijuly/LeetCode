#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution
{
  public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n, 1);
        for (int i = 0, t = 1; i < n; ++i)
        {
            res[i] *= t;
            t *= nums[i];
        }
        for (int i = n - 1, t = 1; i >= 0; --i)
        {
            res[i] *= t;
            t *= nums[i];
        }
        return res;
    }
};
// @lc code=end
