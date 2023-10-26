#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=974 lang=cpp
 *
 * [974] Subarray Sums Divisible by K
 */

// @lc code=start
class Solution
{
  public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        vector<int> count(k);
        int preSum = 0;
        int res = 0;
        for (int num : nums)
        {
            preSum += num;
            int mod = preSum % k;
            if (mod < 0)
            {
                mod += k;
            }
            if (mod)
            {
                res += count[mod];
                ++count[mod];
            }
            else
            {
                ++count[mod];
                res += count[mod];
            }
        }
        return res;
    }
};
// @lc code=end
