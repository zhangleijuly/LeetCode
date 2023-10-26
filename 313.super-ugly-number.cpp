#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=313 lang=cpp
 *
 * [313] Super Ugly Number
 */

// @lc code=start
class Solution
{
  public:
    int nthSuperUglyNumber(int n, vector<int> &primes)
    {
        vector<long> q;
        q.push_back(1);
        int len = primes.size();
        vector<int> index(len, 0);
        while (--n)
        {
            long mn = INT_MAX;
            for (int i = 0; i < len; ++i)
            {
                mn = min(mn, primes[i] * q[index[i]]);
            }
            q.push_back(mn);
            for (int i = 0; i < len; ++i)
            {
                if (mn == primes[i] * q[index[i]])
                {
                    ++index[i];
                }
            }
        }
        return q.back();
    }
};
// @lc code=end
