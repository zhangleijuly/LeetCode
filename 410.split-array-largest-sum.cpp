#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 */

// @lc code=start
class Solution
{
  public:
    int splitArray(vector<int> &nums, int k)
    {
        int l = 0, r = 0;
        for (auto num : nums)
        {
            l = max(l, num);
            r += num;
        }
        while (l < r)
        {
            int m = l + (r - l) / 2;
            int j = calArrs(nums, m);
            if (j == k)
            {
                r = m;
            }
            else if (j < k)
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        return l;
    }
    int calArrs(vector<int> &weights, int cap)
    {
        int cur = 0;
        int days = 0;
        for (auto weight : weights)
        {
            if (cur + weight > cap)
            {
                ++days;
                cur = weight;
            }
            else
            {
                cur += weight;
            }
        }
        return days + 1;
    }
};
// @lc code=end
