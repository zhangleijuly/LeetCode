#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
class Solution
{
  public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        int slow = 0, fast = 0, count = 0;
        while (fast < nums.size())
        {
            if (nums[slow] != nums[fast])
            {
                nums[++slow] = nums[fast];
            }
            else if (slow < fast && count < 2)
            {
                nums[++slow] = nums[fast];
            }
            ++fast;
            ++count;
            if (fast < nums.size() && nums[fast] != nums[fast - 1])
            {
                count = 0;
            }
        }
        return slow + 1;
    }
};
// @lc code=end
