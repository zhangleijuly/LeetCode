#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */

// @lc code=start
class Solution
{
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        auto cmp = [](vector<int> l, vector<int> r) { return l[0] > r[0]; };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < matrix.size(); ++i)
        {
            pq.push({matrix[i][0], i, 0});
        }
        vector<int> res;
        while (!pq.empty() && k > 0)
        {
            --k;
            vector<int> t = pq.top();
            pq.pop();
            if (t[2] + 1 < matrix.size())
            {
                pq.push({matrix[t[1]][t[2] + 1], t[1], t[2] + 1});
            }
            res.push_back(t[0]);
        }
        return res.back();
    }
};
// @lc code=end
