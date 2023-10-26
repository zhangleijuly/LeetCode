#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=220 lang=cpp
 *
 * [220] Contains Duplicate III
 */

// @lc code=start
class Solution
{
  public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int indexDiff, int valueDiff)
    {
        // 记录值和下标
        map<int, int> window;
        int l = 0, r = 0, n = nums.size();
        while (r < n)
        {
            int right = nums[r];
            // 缩小窗口
            while (r - l > indexDiff)
            {
                window.erase(nums[l++]);
            }
            // 在窗口中查找right - valueDiff和right + valueDiff之间的值
            auto it = window.lower_bound(right - valueDiff);
            if (it != window.end() && abs(it->first - right) <= valueDiff)
            {
                return true;
            }
            // 最后把right加入窗口
            window[right] = r++;
        }
        return false;
    }
};
// @lc code=end
