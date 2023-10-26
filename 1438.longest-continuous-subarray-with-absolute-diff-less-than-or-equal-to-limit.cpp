#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1438 lang=cpp
 *
 * [1438] Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
 */

// @lc code=start
class Solution
{
  public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        unordered_map<int, int> count;
        set<int> window;
        int l = 0, r = 0, n = nums.size();
        int res = 0;
        while (r < n)
        {
            int cur = nums[r++];
            ++count[cur];
            window.insert(cur);
            int diff = *window.rbegin() - *window.begin();
            while (diff > limit)
            {
                cur = nums[l++];
                if (--count[cur] == 0)
                {
                    window.erase(cur);
                }
                diff = *window.rbegin() - *window.begin();
            }
            res = max(res, r - l);
        }
        return res;
    }
};
// @lc code=end
