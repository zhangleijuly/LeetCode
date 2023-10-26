#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=327 lang=cpp
 *
 * [327] Count of Range Sum
 */

// @lc code=start
class Solution
{
  public:
    int countRangeSum(vector<int> &nums, int lower, int upper)
    {
        int res = 0;
        long long sum = 0;
        multiset<long long> sums;
        sums.insert(sum);
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            // 对于preSum[i]，求有多少满足lower<=preSum[i]-preSum[j]<=upper的j，其中j<i
            // 整理不等式得到preSum[i]-upper<=preSum[j]<=preSum[i]-lower
            // lower_bound能够找到不小于preSum[i]-upper的最小值的代器
            // upper_bound能够找到大于preSum[i]-upper的最小值的迭代器
            // 用distance计算两个迭代器之间的前缀和数目，即为满足条件的j的数目
            res += distance(sums.lower_bound(sum - upper), sums.upper_bound(sum - lower));
            sums.insert(sum);
        }
        return res;
    }
};
// @lc code=end
