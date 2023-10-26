#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 */

// @lc code=start
class Solution
{
  public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        int preSum = 0;
        map<int, int> hash;
        for (int i = 0; i < n; ++i)
        {
            preSum += nums[i];
            int mod = preSum % k;
            if (mod == 0 && i + 1 >= 2)
            {
                return true;
            }
            if (hash.find(mod) == hash.end())
            {
                hash[mod] = i + 1;
            }
            else
            {
                if (i + 1 - hash[mod] >= 2)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end
