#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
class Solution
{
  public:
    int removeElement(vector<int> &nums, int val)
    {
        int n = nums.size();
        int slow = 0, fast = 0;
        while (fast < n)
        {
            if (nums[fast] != val)
            {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};
// @lc code=end
