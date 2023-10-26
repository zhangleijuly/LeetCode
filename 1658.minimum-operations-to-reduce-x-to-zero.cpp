#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1658 lang=cpp
 *
 * [1658] Minimum Operations to Reduce X to Zero
 */

// @lc code=start
class Solution
{
  public:
    int minOperations(vector<int> &nums, int x)
    {
        int n = nums.size();
        int sum = 0;
        int res = INT_MAX;
        for (int num : nums)
        {
            sum += num;
        }
        if (sum - x < 0)
        {
            return -1;
        }
        if (sum == x)
        {
            return n;
        }
        int l = 0, r = 0;
        int window = 0;
        while (r < n)
        {
            window += nums[r++];
            while (window >= sum - x)
            {
                if (window == sum - x)
                {
                    res = min(res, n - (r - l));
                }
                window -= nums[l++];
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
// @lc code=end
