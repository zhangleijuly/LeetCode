#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=862 lang=cpp
 *
 * [862] Shortest Subarray with Sum at Least K
 */

// @lc code=start
class Solution
{
  public:
    int shortestSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();
        int res = INT_MAX;
        vector<long> preSum(n + 1);
        for (int i = 0; i < n; ++i)
        {
            preSum[i + 1] = preSum[i] + nums[i];
        }
        deque<int> dq;
        dq.push_back(0);
        for (int i = 1; i <= n; ++i)
        {
            // 剪枝，如果preSum[i] - preSum[dq.front()] >= k，那么随着i增大
            // i - dq.front()不会是一个更优的结果，故把dq.front()出队
            while (!dq.empty() && preSum[i] - preSum[dq.front()] >= k)
            {
                res = min(res, i - dq.front());
                dq.pop_front();
            }
            // 剪枝，如果preSum[i] < preSum[dq.back()]，那么对于大于i的j，j - i是比
            // j - dq.back()更优的结果，故把dq.back()出队
            while (!dq.empty() && preSum[i] < preSum[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return res == INT_MAX ? -1 : res;
    }
};
// @lc code=end
