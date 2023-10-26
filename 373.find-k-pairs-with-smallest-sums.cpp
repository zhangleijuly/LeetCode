#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=373 lang=cpp
 *
 * [373] Find K Pairs with Smallest Sums
 */

// @lc code=start
class Solution
{
  public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        auto cmp = [](vector<int> l, vector<int> r) { return l[0] + l[1] > r[0] + r[1]; };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < nums1.size(); ++i)
        {
            pq.push({nums1[i], nums2[0], 0});
        }
        vector<vector<int>> res;
        while (!pq.empty() && k > 0)
        {
            --k;
            vector<int> t = pq.top();
            pq.pop();
            if (t[2] + 1 < nums2.size())
            {
                pq.push({t[0], nums2[t[2] + 1], t[2] + 1});
            }
            res.push_back({t[0], t[1]});
        }
        return res;
    }
};
// @lc code=end
