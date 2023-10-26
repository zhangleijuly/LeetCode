#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

// @lc code=start
class Solution
{
  public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        int l = 0, r = 0;
        for (auto weight : weights)
        {
            l = max(l, weight);
            r += weight;
        }
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (calArrs(weights, m) == days)
            {
                r = m;
            }
            else if (calArrs(weights, m) < days)
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
