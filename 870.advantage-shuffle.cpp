#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=870 lang=cpp
 *
 * [870] Advantage Shuffle
 */

// @lc code=start
class Solution
{
  public:
    vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        auto cmp = [](vector<int> a, vector<int> b) { return b[1] > a[1]; };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < n; ++i)
        {
            pq.push({i, nums2[i]});
        }
        sort(nums1.begin(), nums1.end());

        int l = 0, r = n - 1;
        vector<int> res(n);
        while (!pq.empty())
        {
            vector<int> cur = pq.top();
            pq.pop();
            if (nums1[r] > cur[1])
            {
                res[cur[0]] = nums1[r--];
            }
            else
            {
                res[cur[0]] = nums1[l++];
            }
        }
        return res;
    }
};
// @lc code=end
