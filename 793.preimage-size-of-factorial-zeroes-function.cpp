#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=793 lang=cpp
 *
 * [793] Preimage Size of Factorial Zeroes Function
 */

// @lc code=start
class Solution
{
  public:
    int preimageSizeFZF(int k)
    {
        // 此题的答案非0即5，转化为搜索是否存在满足f(x)=k的x,存在返回5，不存在返回0
        long l = 0, r = 5L * k, m;
        while (l <= r)
        {
            m = l + (r - l) / 2;
            long n = 5, zeros = 0;
            while (n <= m)
            {
                zeros += m / n;
                n *= 5;
            }
            if (zeros == k)
            {
                return 5;
            }
            else if (zeros < k)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        return 0;
    }
};
// @lc code=end
