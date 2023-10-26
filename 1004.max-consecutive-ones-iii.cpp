#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */

// @lc code=start
class Solution
{
  public:
    int longestOnes(vector<int> &nums, int k)
    {
        int count = 0;
        int l = 0, r = 0, n = nums.size();
        int res = 0;
        while (r < n)
        {
            int right = nums[r++];
            if (right == 0)
            {
                ++count;
            }
            while (count > k)
            {
                int left = nums[l++];
                if (left == 0)
                {
                    --count;
                }
            }
            res = max(res, r - l);
        }
        return res;
    }
};
// @lc code=end
