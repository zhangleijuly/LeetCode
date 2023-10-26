#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
class Solution
{
  public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> window;
        int l = 0, r = 0, n = nums.size();
        while (r < n)
        {
            int right = nums[r++];
            ++window[right];
            while (r - l > k + 1)
            {
                int left = nums[l++];
                --window[left];
            }
            if (window[right] >= 2)
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
